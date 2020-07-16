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
    
    Copyright (c) Byteduck 2016-2020. All rights reserved.
*/

#ifndef DUCKOS_YIELDLOCK_H
#define DUCKOS_YIELDLOCK_H

#include "Lock.h"
#include "TaskYieldQueue.h"

class TaskYieldQueue;
class YieldLock: public Lock {
public:
	YieldLock();
	~YieldLock();
	bool locked() override;
	void acquire() override;
	void release() override;
private:
	TaskYieldQueue _yield_queue;
	volatile bool _locked = false;
};


#endif //DUCKOS_YIELDLOCK_H