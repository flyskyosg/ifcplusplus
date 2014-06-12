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
#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "ifcpp/model/shared_ptr.h"
#include "ifcpp/model/IfcPPObject.h"
#include "IfcCompositeCurveSegment.h"
class IfcParameterValue;
//ENTITY
class IfcReparametrisedCompositeCurveSegment : public IfcCompositeCurveSegment
{
public:
	IfcReparametrisedCompositeCurveSegment();
	IfcReparametrisedCompositeCurveSegment( int id );
	~IfcReparametrisedCompositeCurveSegment();

	// method setEntity takes over all attributes from another instance of the class
	virtual void setEntity( shared_ptr<IfcPPEntity> other );
	virtual void getStepLine( std::stringstream& stream ) const;
	virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
	virtual void readStepArguments( const std::vector<std::string>& args, const std::map<int,shared_ptr<IfcPPEntity> >& map );
	virtual void setInverseCounterparts( shared_ptr<IfcPPEntity> ptr_self );
	virtual void getAttributes( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void getAttributesInverse( std::vector<std::pair<std::string, shared_ptr<IfcPPObject> > >& vec_attributes );
	virtual void unlinkSelf();
	virtual const char* classname() const { return "IfcReparametrisedCompositeCurveSegment"; }


	// IfcRepresentationItem -----------------------------------------------------------
	// inverse attributes:
	//  std::vector<weak_ptr<IfcPresentationLayerAssignment> >	m_LayerAssignment_inverse;
	//  std::vector<weak_ptr<IfcStyledItem> >		m_StyledByItem_inverse;

	// IfcGeometricRepresentationItem -----------------------------------------------------------

	// IfcCompositeCurveSegment -----------------------------------------------------------
	// attributes:
	//  shared_ptr<IfcTransitionCode>				m_Transition;
	//  bool											m_SameSense;
	//  shared_ptr<IfcCurve>							m_ParentCurve;
	// inverse attributes:
	//  std::vector<weak_ptr<IfcCompositeCurve> >	m_UsingCurves_inverse;

	// IfcReparametrisedCompositeCurveSegment -----------------------------------------------------------
	// attributes:
	shared_ptr<IfcParameterValue>				m_ParamLength;
};
