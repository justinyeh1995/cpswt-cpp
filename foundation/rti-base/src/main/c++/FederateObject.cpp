// This code has been generated by the C2W code generator.
// Do not edit manually!

#include "FederateObject.hpp"


void FederateObject::init( RTI::RTIambassador *rti ) {
	static bool isInitialized = false;
	if ( isInitialized ) {
		return;
	}
	isInitialized = true;

	ObjectRoot::init( rti );

	bool isNotInitialized = true;
	while( isNotInitialized ) {
		try {
			getHandle() = rti->getObjectClassHandle( "ObjectRoot.Manager.Federate" );
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

	getClassNameHandleMap().insert(  std::make_pair( "FederateObject", get_handle() )  );
	getClassHandleNameMap().insert(  std::make_pair( get_handle(), "FederateObject" )  );

	isNotInitialized = true;
	while( isNotInitialized ) {
		try {		
			get_FederateHandle_handle_var() = rti->getAttributeHandle( "FederateHandle", get_handle() );
			get_FederateType_handle_var() = rti->getAttributeHandle( "FederateType", get_handle() );
			get_FederateHost_handle_var() = rti->getAttributeHandle( "FederateHost", get_handle() );

			isNotInitialized = false;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << getInitErrorMessage() << "Federate Not Execution Member" << std::endl;
			return;				
		} catch ( RTI::ObjectClassNotDefined & ) {
			std::cerr << getInitErrorMessage() << "Object Class Not Defined" << std::endl;
			return;				
		} catch ( RTI::NameNotFound & ) {
			std::cerr << getInitErrorMessage() << "Name Not Found" << std::endl;
			return;				
		} catch ( ... ) {
			std::cerr << getInitErrorMessage() << "Exception caught ... retry" << std::endl;
		}
	}
	getDatamemberNameHandleMap().insert(  std::make_pair( "FederateObject,FederateHandle", get_FederateHandle_handle() )  );
	getDatamemberNameHandleMap().insert(  std::make_pair( "FederateObject,FederateType", get_FederateType_handle() )  );
	getDatamemberNameHandleMap().insert(  std::make_pair( "FederateObject,FederateHost", get_FederateHost_handle() )  );

	getDatamemberHandleNameMap().insert(  std::make_pair( get_FederateHandle_handle(), "FederateHandle" )  );
	getDatamemberHandleNameMap().insert(  std::make_pair( get_FederateType_handle(), "FederateType" )  );
	getDatamemberHandleNameMap().insert(  std::make_pair( get_FederateHost_handle(), "FederateHost" )  );

	getDatamemberTypeMap().insert( std::make_pair("FederateHandle", "int") );
	getDatamemberTypeMap().insert( std::make_pair("FederateType", "String") );
	getDatamemberTypeMap().insert( std::make_pair("FederateHost", "String") );

}

void FederateObject::publish( RTI::RTIambassador *rti ) {
	if ( getIsPublished() ) {
		return;
	}

	init( rti );

	
	getPublishedAttributeHandleSet_var().empty();
	for( StringVector::iterator stsItr = getPublishAttributeNameVector().begin() ; stsItr != getPublishAttributeNameVector().end() ; (void)++stsItr ) {
		try {
			getPublishedAttributeHandleSet_var().add(  getDatamemberNameHandleMap().find( "FederateObject," + *stsItr )->second  );
		} catch ( ... ) {
			std::cerr << getPublishErrorMessage() << "Could not publish \"" << *stsItr + "\" attribute." << std::endl;
		}
	}
	bool isNotPublished = true;
	while( isNotPublished ) {
		try {
			rti->publishObjectClass( get_handle(), getPublishedAttributeHandleSet_var() );
			isNotPublished = false;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << getPublishErrorMessage() << "Federate Not Execution Member" << std::endl;
			return;
		} catch ( RTI::ObjectClassNotDefined & ) {
			std::cerr << getPublishErrorMessage() << "Object Class Not Defined" << std::endl;
			return;
		} catch ( ... ) {
			std::cerr << getPublishErrorMessage() << "Exception caught ... retry" << std::endl;
		}
	}

	getIsPublished() = true;
}

void FederateObject::unpublish( RTI::RTIambassador *rti ) {
	if ( !getIsPublished() ) {
		return;
	}

	init( rti );

	bool isNotUnpublished = true;
	while( isNotUnpublished ) {
		try {
			rti->unpublishObjectClass( get_handle() );
			isNotUnpublished = false;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << getUnpublishErrorMessage() + "Federate Not Execution Member" << std::endl;
			return;
		} catch ( RTI::ObjectClassNotDefined & ) {
			std::cerr << getUnpublishErrorMessage() + "Object Class Not Defined" << std::endl;
			return;
		} catch ( RTI::ObjectClassNotPublished & ) {
			std::cerr << getUnpublishErrorMessage() + "Object Class Not Published" << std::endl;
			return;
		} catch ( ... ) {
			std::cerr << getUnpublishErrorMessage() << "Exception caught ... retry" << std::endl;
		}
	}

	getIsPublished() = false;
}

void FederateObject::subscribe( RTI::RTIambassador *rti ) {
	if ( getIsSubscribed() ) {
		return;
	}

	init( rti );
	
	getSubscribedAttributeHandleSet_var().empty();
	for(  StringVector::iterator sstItr = getSubscribeAttributeNameVector().begin() ; sstItr != getSubscribeAttributeNameVector().end() ; (void)++sstItr  ) {
		try {
			getSubscribedAttributeHandleSet_var().add(  getDatamemberNameHandleMap().find( "FederateObject," + *sstItr )->second  );
		} catch ( ... ) {
			std::cerr << getSubscribeErrorMessage() << "Could not subscribe to \"" << *sstItr << "\" attribute." << std::endl;
		}
	}	
	bool isNotSubscribed = true;
	while( isNotSubscribed ) {
		try {
			rti->subscribeObjectClassAttributes( get_handle(), getSubscribedAttributeHandleSet_var() );
			isNotSubscribed = false;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << getSubscribeErrorMessage() << "Federate Not Execution Member" << std::endl;
			return;
		} catch ( RTI::ObjectClassNotDefined & ) {
			std::cerr << getSubscribeErrorMessage() << "Object Class Not Defined" << std::endl;
			return;
		} catch ( ... ) {
			std::cerr << getSubscribeErrorMessage() << "Exception caught ... retry" << std::endl;
		}
	}

	getIsSubscribed() = true;
}
	
void FederateObject::unsubscribe( RTI::RTIambassador *rti ) {
	if ( !getIsSubscribed() ) {
		return;
	}

	init( rti );
	
	bool isNotUnsubscribed = true;
	while( isNotUnsubscribed ) {
		try {
			rti->unsubscribeObjectClass( get_handle() );
			isNotUnsubscribed = false;
		} catch ( RTI::FederateNotExecutionMember & ) {
			std::cerr << getUnsubscribeErrorMessage() << "Federate Not Execution Member" << std::endl;
			return;
		} catch ( RTI::ObjectClassNotDefined & ) {
			std::cerr << getUnsubscribeErrorMessage() << "Object Class Not Defined" << std::endl;
			return;
		} catch ( RTI::ObjectClassNotSubscribed & ) {
			std::cerr << getUnsubscribeErrorMessage() << "Object Class Not Subscribed" << std::endl;
			return;
		} catch ( ... ) {
			std::cerr << getUnsubscribeErrorMessage() << "Exception caught ... retry" << std::endl;
		}
	}

	getIsSubscribed() = false;
}

bool FederateObject::static_init( void ) {
	static bool isInitialized = false;
	if ( isInitialized ) {
		return true;
	}
	isInitialized = true;
	
	getClassNameSet().insert( "FederateObject" );
	
	getClassNameFactoryMap().insert(  std::make_pair( "FederateObject", &FederateObject::factory )  );
	getClassNamePublishMap().insert(   std::make_pair(  "FederateObject", (PubsubFunctionPtr)( &FederateObject::publish )  )   );
	getClassNameUnpublishMap().insert(   std::make_pair(  "FederateObject", (PubsubFunctionPtr)( &FederateObject::unpublish )  )   );
	getClassNameSubscribeMap().insert(   std::make_pair(  "FederateObject", (PubsubFunctionPtr)( &FederateObject::subscribe )  )   );
	getClassNameUnsubscribeMap().insert(   std::make_pair(  "FederateObject", (PubsubFunctionPtr)( &FederateObject::unsubscribe )  )   );

	getDatamemberClassNameVectorPtrMap().insert(  std::make_pair( "FederateObject", &getDatamemberNames() )  );
	getAllDatamemberClassNameVectorPtrMap().insert(  std::make_pair( "FederateObject", &getAllDatamemberNames() )  );
	
	getDatamemberNames().push_back( "FederateHandle" );
	getDatamemberNames().push_back( "FederateType" );
	getDatamemberNames().push_back( "FederateHost" );

	getAllDatamemberNames().push_back( "FederateHandle" );
	getAllDatamemberNames().push_back( "FederateType" );
	getAllDatamemberNames().push_back( "FederateHost" );

	getClassNamePublishAttributeNameVectorPtrMap().insert(  std::make_pair( "FederateObject", &getPublishAttributeNameVector() )  );
	getClassNameSubscribeAttributeNameVectorPtrMap().insert(  std::make_pair( "FederateObject", &getSubscribeAttributeNameVector() )  );
	
	getClassNamePublishedAttributesPtrMap().insert(  std::make_pair( "FederateObject", &getPublishedAttributeHandleSet_var() )  );
	getClassNameSubscribedAttributesPtrMap().insert( std::make_pair( "FederateObject", &getSubscribedAttributeHandleSet_var() )  );
	return true;
}

std::ostream &operator<<( std::ostream &os, FederateObject::SP entitySP ) {
	return os << *entitySP;
}
std::ostream &operator<<( std::ostream &os, const FederateObject &entity ) {
	return os << "FederateObject("
	<< "FederateHandle:" << entity.get_FederateHandle()
	<< "," << "FederateType:" << entity.get_FederateType()
	<< "," << "FederateHost:" << entity.get_FederateHost()
	<< ")";
}
	

FederateObject::AttributeHandleValuePairSetSP FederateObject::createDatamemberHandleValuePairSet( RTI::ULong count, bool force  ) {
	AttributeHandleValuePairSetSP datamembers = Super::createDatamemberHandleValuePairSet( count + 3, force );

	std::string stringConversion;
		
	bool isPublished = false;
	try {
		isPublished = getPublishedAttributeHandleSet_var().isMember( get_FederateHandle_handle() );
	} catch ( ... ) {
		std::cerr << "ERROR:  FederateObject.createSuppliedAttributes:  could not determine if FederateHandle is published." << std::endl;
		isPublished = false;
	}
	if (  isPublished && _FederateHandle.shouldBeUpdated( force )  ) {
		stringConversion = static_cast< std::string >(  TypeMedley( get_FederateHandle() )  );
		datamembers->add( get_FederateHandle_handle(), stringConversion.c_str(), stringConversion.size() );
		_FederateHandle.setHasBeenUpdated();
	}
	try {
		isPublished = getPublishedAttributeHandleSet_var().isMember( get_FederateType_handle() );
	} catch ( ... ) {
		std::cerr << "ERROR:  FederateObject.createSuppliedAttributes:  could not determine if FederateType is published." << std::endl;
		isPublished = false;
	}
	if (  isPublished && _FederateType.shouldBeUpdated( force )  ) {
		stringConversion = static_cast< std::string >(  TypeMedley( get_FederateType() )  );
		datamembers->add( get_FederateType_handle(), stringConversion.c_str(), stringConversion.size() );
		_FederateType.setHasBeenUpdated();
	}
	try {
		isPublished = getPublishedAttributeHandleSet_var().isMember( get_FederateHost_handle() );
	} catch ( ... ) {
		std::cerr << "ERROR:  FederateObject.createSuppliedAttributes:  could not determine if FederateHost is published." << std::endl;
		isPublished = false;
	}
	if (  isPublished && _FederateHost.shouldBeUpdated( force )  ) {
		stringConversion = static_cast< std::string >(  TypeMedley( get_FederateHost() )  );
		datamembers->add( get_FederateHost_handle(), stringConversion.c_str(), stringConversion.size() );
		_FederateHost.setHasBeenUpdated();
	}
	return datamembers;
}