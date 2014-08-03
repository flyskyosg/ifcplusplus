/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com - Copyright (C) 2011 Fabian Gerold
*
* This library is open source and may be redistributed and/or modified under  
* the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
* (at your option) any later version.  The full license is in LICENSE file
* included with this distribution, and on the openscenegraph.org website.
* 
* This library is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
* OpenSceneGraph Public License for more details.
*/
#include <sstream>
#include <limits>

#include "ifcpp/model/IfcPPException.h"
#include "ifcpp/model/IfcPPAttributeObject.h"
#include "ifcpp/reader/ReaderUtil.h"
#include "ifcpp/writer/WriterUtil.h"
#include "ifcpp/IfcPPEntityEnums.h"
#include "include/IfcGloballyUniqueId.h"
#include "include/IfcGroup.h"
#include "include/IfcLabel.h"
#include "include/IfcObjectDefinition.h"
#include "include/IfcObjectTypeEnum.h"
#include "include/IfcOwnerHistory.h"
#include "include/IfcRatioMeasure.h"
#include "include/IfcRelAssignsToGroupByFactor.h"
#include "include/IfcText.h"

// ENTITY IfcRelAssignsToGroupByFactor 
IfcRelAssignsToGroupByFactor::IfcRelAssignsToGroupByFactor() {}
IfcRelAssignsToGroupByFactor::IfcRelAssignsToGroupByFactor( int id ) { m_id = id; }
IfcRelAssignsToGroupByFactor::~IfcRelAssignsToGroupByFactor() {}
shared_ptr<IfcPPObject> IfcRelAssignsToGroupByFactor::getDeepCopy()
{
	shared_ptr<IfcRelAssignsToGroupByFactor> copy_self( new IfcRelAssignsToGroupByFactor() );
	if( m_GlobalId ) { copy_self->m_GlobalId = dynamic_pointer_cast<IfcGloballyUniqueId>( m_GlobalId->getDeepCopy() ); }
	if( m_OwnerHistory ) { copy_self->m_OwnerHistory = dynamic_pointer_cast<IfcOwnerHistory>( m_OwnerHistory->getDeepCopy() ); }
	if( m_Name ) { copy_self->m_Name = dynamic_pointer_cast<IfcLabel>( m_Name->getDeepCopy() ); }
	if( m_Description ) { copy_self->m_Description = dynamic_pointer_cast<IfcText>( m_Description->getDeepCopy() ); }
	for( size_t ii=0; ii<m_RelatedObjects.size(); ++ii )
	{
		auto item_ii = m_RelatedObjects[ii];
		if( item_ii )
		{
			copy_self->m_RelatedObjects.push_back( dynamic_pointer_cast<IfcObjectDefinition>(item_ii->getDeepCopy() ) );
		}
	}
	if( m_RelatedObjectsType ) { copy_self->m_RelatedObjectsType = dynamic_pointer_cast<IfcObjectTypeEnum>( m_RelatedObjectsType->getDeepCopy() ); }
	if( m_RelatingGroup ) { copy_self->m_RelatingGroup = dynamic_pointer_cast<IfcGroup>( m_RelatingGroup->getDeepCopy() ); }
	if( m_Factor ) { copy_self->m_Factor = dynamic_pointer_cast<IfcRatioMeasure>( m_Factor->getDeepCopy() ); }
	return copy_self;
}
void IfcRelAssignsToGroupByFactor::getStepLine( std::stringstream& stream ) const
{
	stream << "#" << m_id << "= IFCRELASSIGNSTOGROUPBYFACTOR" << "(";
	if( m_GlobalId ) { m_GlobalId->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_OwnerHistory ) { stream << "#" << m_OwnerHistory->getId(); } else { stream << "*"; }
	stream << ",";
	if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_Description ) { m_Description->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	writeEntityList( stream, m_RelatedObjects );
	stream << ",";
	if( m_RelatedObjectsType ) { m_RelatedObjectsType->getStepParameter( stream ); } else { stream << "*"; }
	stream << ",";
	if( m_RelatingGroup ) { stream << "#" << m_RelatingGroup->getId(); } else { stream << "*"; }
	stream << ",";
	if( m_Factor ) { m_Factor->getStepParameter( stream ); } else { stream << "$"; }
	stream << ");";
}
void IfcRelAssignsToGroupByFactor::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
void IfcRelAssignsToGroupByFactor::readStepArguments( const std::vector<std::wstring>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map )
{
	const int num_args = (int)args.size();
	if( num_args<8 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRelAssignsToGroupByFactor, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcPPException( strserr.str().c_str() ); }
	#ifdef _DEBUG
	if( num_args>8 ){ std::cout << "Wrong parameter count for entity IfcRelAssignsToGroupByFactor, expecting 8, having " << num_args << ". Object id: " << getId() << std::endl; }
	#endif
	m_GlobalId = IfcGloballyUniqueId::createObjectFromStepData( args[0] );
	readEntityReference( args[1], m_OwnerHistory, map );
	m_Name = IfcLabel::createObjectFromStepData( args[2] );
	m_Description = IfcText::createObjectFromStepData( args[3] );
	readEntityReferenceList( args[4], m_RelatedObjects, map );
	m_RelatedObjectsType = IfcObjectTypeEnum::createObjectFromStepData( args[5] );
	readEntityReference( args[6], m_RelatingGroup, map );
	m_Factor = IfcRatioMeasure::createObjectFromStepData( args[7] );
}
void IfcRelAssignsToGroupByFactor::getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes )
{
	IfcRelAssignsToGroup::getAttributes( vec_attributes );
	vec_attributes.push_back( std::make_pair( "Factor", m_Factor ) );
}
void IfcRelAssignsToGroupByFactor::getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes_inverse )
{
	IfcRelAssignsToGroup::getAttributesInverse( vec_attributes_inverse );
}
void IfcRelAssignsToGroupByFactor::setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self_entity )
{
	IfcRelAssignsToGroup::setInverseCounterparts( ptr_self_entity );
}
void IfcRelAssignsToGroupByFactor::unlinkSelf()
{
	IfcRelAssignsToGroup::unlinkSelf();
}
