
#include <iostream>
#include "HostInputHandler.h"

namespace AccGrind {
    HostInputHandler::HostInputHandler () {
    }
    HostInputHandler::~HostInputHandler () {}

    bool HostInputHandler::handleInput ( std::string& usrInput ) {
        Task task = getHostTaskFrom ( usrInput );
        if ( task ) {
            scheduleTask( task );
        }else{
            if ( false == plugin_handleInput ( usrInput ) ) {
                // report error -- invalid input
                return false;
            }
        }
        return true;
    }
    Task HostInputHandler::getHostTaskFrom ( std::string & usrInput ) {
        Task newTask;
        newTask = m_interpreter.interpret ( usrInput );
        return newTask;
    }
    void HostInputHandler::getOptions ( std::vector<std::string> & usrOptionVector ) const {
        m_interpreter.getOptions(usrOptionVector);
    }
    void HostInputHandler::scheduleTask ( Task task){
        //m_hostTaskQueue.add ( task );
        task->execute();
    }
    bool HostInputHandler::plugin_handleInput ( std::string const&  ){
        return false;
    }
}
