
#include "InputRouter.h"
#include <iostream>

namespace AccGrind {
    InputRouter::InputRouter ( KeyInputSource &inputSrc, HostInputHandler &InputHandler ): m_InputSource(inputSrc), m_InputHandler(InputHandler){
    }
    InputRouter::~InputRouter ( ){}

    void InputRouter::process (){
        std::ostream& outStream = m_InputSource.getOutputStream();
        while ( m_InputSource.hasMoreData() ){
            std::vector<std::string>  optionVector;
            m_InputHandler.getOptions(optionVector);
            int optionIndex = 0;
            for ( auto a:optionVector ) {
                outStream << "  "<< a.c_str() << std::endl;
            }
            outStream << "---------> choose option with input :" ;
            std::string usrInput = m_InputSource.getNextInput();
            outStream  << "------------------------- handling input :" << usrInput << std::endl;
            bool isInputHandled = m_InputHandler.handleInput ( usrInput );
            if ( !isInputHandled ){
                outStream  << "Error: Input not supported -- stopping processing loop" << usrInput << std::endl;
                break;
            }// else {continue; // the loop }
        }
    }
}

