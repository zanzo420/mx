// MusicXML Class Library v0.2
// Copyright (c) 2015 - 2016 by Matthew James Briggs

#include "mx/core/elements/PartAttributes.h"
#include "mx/core/FromXElement.h"
#include <iostream>

namespace mx
{
    namespace core
    {
        PartAttributes::PartAttributes()
        :id()
        ,hasId( true )
        {}


        bool PartAttributes::hasValues() const
        {
            return hasId;
        }


        std::ostream& PartAttributes::toStream( std::ostream& os ) const
        {
            if ( hasValues() )
            {
                streamAttribute( os, id, "id", hasId );
            }
            return os;
        }


        bool PartAttributes::fromXElement( std::ostream& message, xml::XElement& xelement )
        {
            const char* const className = "PartAttributes";
            bool isSuccess = true;
            bool isIdFound = false;
        
            auto it = xelement.attributesBegin();
            auto endIter = xelement.attributesEnd();
        
            for( ; it != endIter; ++it )
            {
                if( parseAttribute( message, it, className, isSuccess, id, isIdFound, "id" ) ) { continue; }
            }
        
            if( !isIdFound )
            {
                isSuccess = false;
                message << className << ": 'id' is a required attribute but was not found" << std::endl;
            }
        
            MX_RETURN_IS_SUCCESS;
        }

    }
}