/*
    This file is part of duckOS.

    duckOS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    duckOS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with duckOS.  If not, see <https://www.gnu.org/licenses/>.

    Copyright (c) Byteduck 2016-2021. All rights reserved.
*/

#ifndef DUCKOS_LIBRIVER_MESSAGE_HPP
#define DUCKOS_LIBRIVER_MESSAGE_HPP

#include "packet.h"
#include "Endpoint.h"
#include <type_traits>

namespace River {
	class IMessage {
	public:
		virtual void handle_message(const RiverPacket& packet) const = 0;
		virtual const std::string& path() const = 0;
	};

	template<typename T>
	class Message: public IMessage {
		static_assert(std::is_pod<T>(), "Message type must be a plain-old datatype!");

	public:
		Message(const std::string& path): _path(path), _endpoint(nullptr), _callback(nullptr) {}

		Message(const std::string& path, std::shared_ptr<Endpoint> endpoint):
				_path(stringname_of(path)),
				_endpoint(std::move(endpoint)) {}

		Message(const std::string& path, std::shared_ptr<Endpoint> endpoint, std::function<void(T)> callback):
				_path(stringname_of(path)),
				_endpoint(std::move(endpoint)),
				_callback(callback) {}

		static std::string stringname_of(const std::string& path) {
			return path + "<" + typeid(T).name() + "[" + std::to_string(sizeof(T)) + "]>";
		}

		void send(sockid_t recipient, const T& data) const {
			if(!_endpoint) {
				fprintf(stderr, "[River] WARN: Tried sending uninitialized message %s!\n", _path.c_str());
				return;
			}

			if(_endpoint->type() == Endpoint::HOST) {
				RiverPacket packet = {
						SEND_MESSAGE,
						_endpoint->name(),
						_path
				};
				packet.recipient = recipient;

				//Serialize message data
				packet.data.resize(sizeof(T));
				memcpy(packet.data.data(), &data, sizeof(T));

				//Send the message packet
				_endpoint->bus()->send_packet(packet);
			} else {
				fprintf(stderr, "[River] WARN: Tried sending message through proxy endpoint!\n");
			}
		}

		const std::string& path() const override {
			return _path;
		}


		virtual void set_callback(std::function<void(T)> callback) {
			if(!_endpoint) {
				fprintf(stderr, "[River] WARN: Tried setting callback for uninitialized message!\n");
				return;
			}

			if(_endpoint->type() == Endpoint::HOST) {
				fprintf(stderr, "[River] WARN: Tried setting callback for message on host!\n");
				return;
			}

			_callback = callback;
		}

		void handle_message(const RiverPacket& packet) const override {
			if(!_callback)
				return;
			T ret;
			if(packet.data.size() != sizeof(T))
				return;
			memcpy(&ret, packet.data.data(), sizeof(T));
			_callback(ret);
		}

	private:
		std::string _path;
		std::shared_ptr<Endpoint> _endpoint;
		std::function<void(T)> _callback = nullptr;
	};
}

#endif //DUCKOS_LIBRIVER_MESSAGE_HPP
