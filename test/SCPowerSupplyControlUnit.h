/*
 *	SCPowerSupplyControlUnit.h
 *	!CHOAS
 *	Created by Claudio Bisegni.
 *
 *    	Copyright 2013 INFN, National Institute of Nuclear Physics
 *
 *    	Licensed under the Apache License, Version 2.0 (the "License");
 *    	you may not use this file except in compliance with the License.
 *    	You may obtain a copy of the License at
 *
 *    	http://www.apache.org/licenses/LICENSE-2.0
 *
 *    	Unless required by applicable law or agreed to in writing, software
 *    	distributed under the License is distributed on an "AS IS" BASIS,
 *    	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    	See the License for the specific language governing permissions and
 *    	limitations under the License.
 */
#ifndef __PowerSupply__SCPowerSupplyControlUnit__
#define __PowerSupply__SCPowerSupplyControlUnit__


#include "PowerSupplyStateMachine.h"


#include <chaos/cu_toolkit/ControlManager/SCAbstractControlUnit.h>
#include <driver/powersupply/core/ChaosPowerSupplyInterface.h>


using namespace boost::msm::front::euml;
using namespace boost::msm::front;
//namespace mpl = boost::mpl;

namespace driver {
	namespace powersupply {


		
		class SCPowerSupplyControlUnit : public chaos::cu::SCAbstractControlUnit {
			// init paramter
			string device_id;
			string params;
            chaos::driver::powersupply::ChaosPowerSupplyInterface *powersupply_drv;
			
			boost::msm::back::state_machine< powersupply_state_machine_impl > powersupply_sm;
			
		protected:
			/*
			 Define the Control Unit Dataset and Actions
			 */
			void unitDefineActionAndDataset()throw(chaos::CException);
			
			void defineSharedVariable();
			
			void unitDefineDriver(std::vector<chaos::cu::cu_driver::DrvRequestInfo>& neededDriver);
			/*(Optional)
			 Initialize the Control Unit and all driver, with received param from MetadataServer
			 */
			void unitInit() throw(chaos::CException);
			/*(Optional)
			 Execute the work, this is called with a determinated delay, it must be as fast as possible
			 */
			void unitStart() throw(chaos::CException);
			/*(Optional)
			 The Control Unit will be stopped
			 */
			void unitStop() throw(chaos::CException);
			/*(Optional)
			 The Control Unit will be deinitialized and disposed
			 */
			void unitDeinit() throw(chaos::CException);
			
		public:
			/*
			 Construct a new CU with an identifier
			 */
			SCPowerSupplyControlUnit(string _device_id, string _params);
			
			/*
			 Base destructor
			 */
			~SCPowerSupplyControlUnit();
		};
	}
}

#endif /* defined(__PowerSupply__SCPowerSupplyControlUnit__) */