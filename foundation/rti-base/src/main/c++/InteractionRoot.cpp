// This code has been generated by the C2W code generator.
// Do not edit manually!

/*
 * Copyright (c) 2008, Institute for Software Integrated Systems, Vanderbilt University
 * All rights reserved.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose, without fee, and without written agreement is
 * hereby granted, provided that the above copyright notice, the following
 * two paragraphs and the author appear in all copies of this software.
 *
 * IN NO EVENT SHALL THE VANDERBILT UNIVERSITY BE LIABLE TO ANY PARTY FOR
 * DIRECT, INDIRECT, SPECIAL, INCIDENTAL, OR CONSEQUENTIAL DAMAGES ARISING OUT
 * OF THE USE OF THIS SOFTWARE AND ITS DOCUMENTATION, EVEN IF THE VANDERBILT
 * UNIVERSITY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * THE VANDERBILT UNIVERSITY SPECIFICALLY DISCLAIMS ANY WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
 * AND FITNESS FOR A PARTICULAR PURPOSE.  THE SOFTWARE PROVIDED HEREUNDER IS
 * ON AN "AS IS" BASIS, AND THE VANDERBILT UNIVERSITY HAS NO OBLIGATION TO
 * PROVIDE MAINTENANCE, SUPPORT, UPDATES, ENHANCEMENTS, OR MODIFICATIONS.
 *
 * @author Himanshu Neema
 * @author Harmon Nine
 */

#include <boost/lexical_cast.hpp>
#include "InteractionRoot.hpp"


C2WLogger* InteractionRoot::_logger = &C2W_RTI_LOGGER_CLS::get_singleton();

void InteractionRoot::init( RTI::RTIambassador *rti ) {
	static bool isInitialized = false;
	if ( isInitialized ) {
		return;
	}
	isInitialized = true;


	bool isNotInitialized = true;
	while( isNotInitialized ) {
		try {
			getHandle() = rti->getInteractionClassHandle( "InteractionRoot" );
			isNotInitialized = false;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << getInitErrorMessage() << "Federate Not Execution Member" << std::endl;
			return;				
		} catch ( RTI::NameNotFound & ) {
			std::cerr << getInitErrorMessage() << "Name Not Found" << std::endl;
			return;				
		} catch ( ... ) {
			std::cerr << getInitErrorMessage() << "Exception caught ... retry" << std::endl;
		}
	}

	getClassNameHandleMap().insert(  std::make_pair( "InteractionRoot", get_handle() )  );
	getClassHandleNameMap().insert(  std::make_pair( get_handle(), "InteractionRoot" )  );

}

void InteractionRoot::publish( RTI::RTIambassador *rti ) {
	if ( getIsPublished() ) {
		return;
	}

	init( rti );

	bool isNotPublished = true;
	while( isNotPublished ) {
		try {
			rti->publishInteractionClass( get_handle() );
			isNotPublished = false;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << getPublishErrorMessage() << "Federate Not Execution Member" << std::endl;
			return;
		} catch ( RTI::InteractionClassNotDefined & ) {
			std::cerr << getPublishErrorMessage() << "Interaction Class Not Defined" << std::endl;
			return;
		} catch ( ... ) {
			std::cerr << getPublishErrorMessage() << "Exception caught ... retry" << std::endl;
		}
	}

	getIsPublished() = true;
}

void InteractionRoot::unpublish( RTI::RTIambassador *rti ) {
	if ( !getIsPublished() ) {
		return;
	}

	init( rti );

	bool isNotUnpublished = true;
	while( isNotUnpublished ) {
		try {
			rti->unpublishInteractionClass( get_handle() );
			isNotUnpublished = false;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << getUnpublishErrorMessage() + "Federate Not Execution Member" << std::endl;
			return;
		} catch ( RTI::InteractionClassNotDefined & ) {
			std::cerr << getUnpublishErrorMessage() + "Interaction Class Not Defined" << std::endl;
			return;
		} catch ( RTI::InteractionClassNotPublished & ) {
			std::cerr << getUnpublishErrorMessage() + "Interaction Class Not Published" << std::endl;
			return;
		} catch ( ... ) {
			std::cerr << getUnpublishErrorMessage() << "Exception caught ... retry" << std::endl;
		}
	}

	getIsPublished() = false;
}

void InteractionRoot::subscribe( RTI::RTIambassador *rti ) {
	if ( getIsSubscribed() ) {
		return;
	}

	init( rti );
	
	bool isNotSubscribed = true;
	while( isNotSubscribed ) {
		try {
			rti->subscribeInteractionClass( get_handle() );
			isNotSubscribed = false;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << getSubscribeErrorMessage() << "Federate Not Execution Member" << std::endl;
			return;
		} catch ( RTI::InteractionClassNotDefined & ) {
			std::cerr << getSubscribeErrorMessage() << "Interaction Class Not Defined" << std::endl;
			return;
		} catch ( ... ) {
			std::cerr << getSubscribeErrorMessage() << "Exception caught ... retry" << std::endl;
		}
	}

	getIsSubscribed() = true;
}
	
void InteractionRoot::unsubscribe( RTI::RTIambassador *rti ) {
	if ( !getIsSubscribed() ) {
		return;
	}

	init( rti );
	
	bool isNotUnsubscribed = true;
	while( isNotUnsubscribed ) {
		try {
			rti->unsubscribeInteractionClass( get_handle() );
			isNotUnsubscribed = false;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << getUnsubscribeErrorMessage() << "Federate Not Execution Member" << std::endl;
			return;
		} catch ( RTI::InteractionClassNotDefined & ) {
			std::cerr << getUnsubscribeErrorMessage() << "Interaction Class Not Defined" << std::endl;
			return;
		} catch ( RTI::InteractionClassNotSubscribed & ) {
			std::cerr << getUnsubscribeErrorMessage() << "Interaction Class Not Subscribed" << std::endl;
			return;
		} catch ( ... ) {
			std::cerr << getUnsubscribeErrorMessage() << "Exception caught ... retry" << std::endl;
		}
	}

	getIsSubscribed() = false;
}

bool InteractionRoot::static_init( void ) {
	static bool isInitialized = false;
	if ( isInitialized ) {
		return true;
	}
	isInitialized = true;
	
	getClassNameSet().insert( "InteractionRoot" );
	
	getClassNameFactoryMap().insert(  std::make_pair( "InteractionRoot", &InteractionRoot::factory )  );
	getClassNamePublishMap().insert(   std::make_pair(  "InteractionRoot", (PubsubFunctionPtr)( &InteractionRoot::publish )  )   );
	getClassNameUnpublishMap().insert(   std::make_pair(  "InteractionRoot", (PubsubFunctionPtr)( &InteractionRoot::unpublish )  )   );
	getClassNameSubscribeMap().insert(   std::make_pair(  "InteractionRoot", (PubsubFunctionPtr)( &InteractionRoot::subscribe )  )   );
	getClassNameUnsubscribeMap().insert(   std::make_pair(  "InteractionRoot", (PubsubFunctionPtr)( &InteractionRoot::unsubscribe )  )   );

	getDatamemberClassNameVectorPtrMap().insert(  std::make_pair( "InteractionRoot", &getDatamemberNames() )  );
	getAllDatamemberClassNameVectorPtrMap().insert(  std::make_pair( "InteractionRoot", &getAllDatamemberNames() )  );
	
	return true;
}

std::ostream &operator<<( std::ostream &os, InteractionRoot::SP entitySP ) {
	return os << *entitySP;
}
std::ostream &operator<<( std::ostream &os, const InteractionRoot &entity ) {
	return os << "InteractionRoot("
	<< ")";
}
	

	
InteractionRoot::SP InteractionRoot::create_interaction( int classHandle, const RTI::ParameterHandleValuePairSet &datamemberMap ) {
	IntegerStringMap::iterator ismItr = getClassHandleNameMap().find( classHandle );
	if ( ismItr == getClassHandleNameMap().end() ) {
		return SP( (InteractionRoot *)0 );
	}
	
	ClassNameFactoryMap::iterator cfmItr = getClassNameFactoryMap().find( ismItr->second );
	if ( cfmItr == getClassNameFactoryMap().end() ) {
		return SP( (InteractionRoot *)0 );
	}
	
	SP sp = (*cfmItr->second)();
	sp->setParameters( datamemberMap );

	return sp;
}

InteractionRoot::SP InteractionRoot::create_interaction( int classHandle, const RTI::ParameterHandleValuePairSet &datamemberMap, const RTIfedTime &dlc13FedTime ) {
	IntegerStringMap::iterator ismItr = getClassHandleNameMap().find( classHandle );
	if ( ismItr == getClassHandleNameMap().end() ) {
		return SP( (InteractionRoot *)0 );
	}
	
	ClassNameFactoryMap::iterator cfmItr = getClassNameFactoryMap().find( ismItr->second );
	if ( cfmItr == getClassNameFactoryMap().end() ) {
		return SP( (InteractionRoot *)0 );
	}
	
	SP sp = (*cfmItr->second)();
	sp->setParameters( datamemberMap );
	sp->setTime( dlc13FedTime.getTime() );

	return sp;
}


void InteractionRoot::setParameters( const RTI::ParameterHandleValuePairSet &datamemberMap ) {
	int size = datamemberMap.size();
	for( int ix = 0 ; ix < size ; ++ix ) {
		try {
			static RTI::ULong valueLength;
			char *value = datamemberMap.getValuePointer( ix, valueLength );
			setParameter(  datamemberMap.getHandle( ix ), std::string( value, valueLength )  );
		} catch ( ... ) {
			std::cerr << "setParameters: Exception caught!" << std::endl;
		}
	}
}

void InteractionRoot::sendInteraction( RTI::RTIambassador *rti, double time ) {
	bool interactionNotSent = true;
	while( interactionNotSent ) {
		try {
			ParameterHandleValuePairSetSP datamembers = createDatamemberHandleValuePairSet( 0 );
			rti->sendInteraction(  getClassHandle(), *datamembers, RTIfedTime( time ), 0  );
			createLog( time, true );
			interactionNotSent = false;
		} catch ( RTI::InteractionClassNotDefined & ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  Interaction Class Not Defined" << std::endl;
			return;
		} catch ( RTI::InteractionClassNotPublished & ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  Interaction Class Not Published" << std::endl;
			return;
		} catch ( RTI::InteractionParameterNotDefined & ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  Interaction Parameter Not Defined" << std::endl;
			return;
		} catch ( RTI::InvalidFederationTime & ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  Invalid Federation Time" << std::endl;
			return;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  Federate Not Execution Member" << std::endl;
			return;
		} catch ( RTI::ConcurrentAccessAttempted & ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  ConcurrentAccessAttempted" << std::endl;
			return;
		} catch ( ... ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  Exception caught ... retry" << std::endl;
#ifdef _WIN32
			Sleep( 500 );
#else
			usleep( 500000 );
#endif
		}
	}
}

void InteractionRoot::sendInteraction( RTI::RTIambassador *rti ) {
	bool interactionNotSent = true;
	while( interactionNotSent ) {
		try {
			ParameterHandleValuePairSetSP datamembers = createDatamemberHandleValuePairSet( 0 );
			rti->sendInteraction(  getClassHandle(), *datamembers, 0  );
			createLog( 0, true );
		} catch ( RTI::InteractionClassNotDefined & ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  Interaction Class Not Defined" << std::endl;
			return;
		} catch ( RTI::InteractionClassNotPublished & ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  Interaction Class Not Published" << std::endl;
			return;
		} catch ( RTI::InteractionParameterNotDefined & ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  Interaction Parameter Not Defined" << std::endl;
			return;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  Federate Not Execution Member" << std::endl;
			return;
		} catch ( RTI::ConcurrentAccessAttempted & ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  ConcurrentAccessAttempted" << std::endl;
			return;
		} catch ( ... ) {
			std::cerr << "ERROR:  " << getClassName() << ":  could not send interaction:  Exception caught ... retry" << std::endl;
#ifdef _WIN32
			Sleep( 500 );
#else
			usleep( 500000 );
#endif
		}
	}
}

std::string InteractionRoot::fedName = "";
bool InteractionRoot::enablePubLog = false;
bool InteractionRoot::enableSubLog = false;
std::string InteractionRoot::pubLogLevel = "";
std::string InteractionRoot::subLogLevel = "";

void InteractionRoot::enablePublishLog( const std::string &interaction, const std::string &fed, const std::string &thislevel, const std::string &globallevel ) {
	if ( globallevel.empty() ) {
		return;
	}
	if (  _logger->getLogLevel( thislevel ) > _logger->getLogLevel( globallevel )  ) {
		return;
	}
	fedName = fed;
	enablePubLog = true;
	pubLogLevel = thislevel;
	_logger->addLog(interaction, fedName, true);
}

void InteractionRoot::enableSubscribeLog( const std::string &interaction, const std::string &fed, const std::string &thislevel, const std::string &globallevel ) {
	if ( globallevel.empty() ) {
		return;
	}
	if (  _logger->getLogLevel( thislevel ) > _logger->getLogLevel( globallevel )  ) {
		return;
	}
	fedName = fed;
	enableSubLog = true;
	subLogLevel = thislevel;
	_logger->addLog( interaction, fedName, false );
}

void InteractionRoot::createLog( double time, bool isPub ) {
	if (  ( isPub && !enablePubLog ) || ( !isPub && !enableSubLog )  ) {
		return;
	}

	std::string interactionId;
	if ( isPub ) {
		interactionId = "pub_" + getClassName();
		if ( !fedName.empty() ) {
			interactionId = fedName + "_" + interactionId;
		}
	} else {
		interactionId = getClassName() + "_sub";
		if ( !fedName.empty() ) {
			interactionId += "_" + fedName;
		}
	}
	
	_logger->addLog( interactionId, *this, time, pubLogLevel );
}
