// This code has been generated by the C2W code generator.
// Do not edit manually!

#include "VeryLowPrio.hpp"


void VeryLowPrio::init( RTI::RTIambassador *rti ) {
	static bool isInitialized = false;
	if ( isInitialized ) {
		return;
	}
	isInitialized = true;

	SimLog::init( rti );

	bool isNotInitialized = true;
	while( isNotInitialized ) {
		try {
			getHandle() = rti->getInteractionClassHandle( "InteractionRoot.C2WInteractionRoot.SimLog.VeryLowPrio" );
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

	getClassNameHandleMap().insert(  std::make_pair( "VeryLowPrio", get_handle() )  );
	getClassHandleNameMap().insert(  std::make_pair( get_handle(), "VeryLowPrio" )  );

}

void VeryLowPrio::publish( RTI::RTIambassador *rti ) {
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

void VeryLowPrio::unpublish( RTI::RTIambassador *rti ) {
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

void VeryLowPrio::subscribe( RTI::RTIambassador *rti ) {
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
	
void VeryLowPrio::unsubscribe( RTI::RTIambassador *rti ) {
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

bool VeryLowPrio::static_init( void ) {
	static bool isInitialized = false;
	if ( isInitialized ) {
		return true;
	}
	isInitialized = true;
	
	getClassNameSet().insert( "VeryLowPrio" );
	
	getClassNameFactoryMap().insert(  std::make_pair( "VeryLowPrio", &VeryLowPrio::factory )  );
	getClassNamePublishMap().insert(   std::make_pair(  "VeryLowPrio", (PubsubFunctionPtr)( &VeryLowPrio::publish )  )   );
	getClassNameUnpublishMap().insert(   std::make_pair(  "VeryLowPrio", (PubsubFunctionPtr)( &VeryLowPrio::unpublish )  )   );
	getClassNameSubscribeMap().insert(   std::make_pair(  "VeryLowPrio", (PubsubFunctionPtr)( &VeryLowPrio::subscribe )  )   );
	getClassNameUnsubscribeMap().insert(   std::make_pair(  "VeryLowPrio", (PubsubFunctionPtr)( &VeryLowPrio::unsubscribe )  )   );

	getDatamemberClassNameVectorPtrMap().insert(  std::make_pair( "VeryLowPrio", &getDatamemberNames() )  );
	getAllDatamemberClassNameVectorPtrMap().insert(  std::make_pair( "VeryLowPrio", &getAllDatamemberNames() )  );
	
	getAllDatamemberNames().push_back( "originFed" );
	getAllDatamemberNames().push_back( "FedName" );
	getAllDatamemberNames().push_back( "sourceFed" );
	getAllDatamemberNames().push_back( "Time" );
	getAllDatamemberNames().push_back( "Comment" );

	return true;
}

std::ostream &operator<<( std::ostream &os, VeryLowPrio::SP entitySP ) {
	return os << *entitySP;
}
std::ostream &operator<<( std::ostream &os, const VeryLowPrio &entity ) {
	return os << "VeryLowPrio("
	<< "originFed:" << entity.get_originFed()
	<< "," << "FedName:" << entity.get_FedName()
	<< "," << "sourceFed:" << entity.get_sourceFed()
	<< "," << "Time:" << entity.get_Time()
	<< "," << "Comment:" << entity.get_Comment()
	<< ")";
}
	

