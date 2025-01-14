// MusicXML Class Library
// Copyright (c) by Matthew James Briggs
// Distributed under the MIT License

#include "mxtest/control/CompileControl.h"
#ifdef MX_COMPILE_CORE_TESTS

#include "cpul/cpulTestHarness.h"
#include "mxtest/core/HelperFunctions.h"
#include "mxtest/core/ScoreInstrumentTest.h"
#include "mxtest/core/VirtualInstrumentTest.h"
#include "mxtest/core/EncodingTest.h"

using namespace mx::core;
using namespace std;
using namespace mxtest;

TEST( Test01, ScoreInstrument )
{
    TestMode v = TestMode::one;
	ScoreInstrumentPtr object = tgenScoreInstrument( v );
	stringstream expected;
	tgenScoreInstrumentExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test02, ScoreInstrument )
{
    TestMode v = TestMode::two;
	ScoreInstrumentPtr object = tgenScoreInstrument( v );
	stringstream expected;
	tgenScoreInstrumentExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( object->hasAttributes() )
	CHECK( object->hasContents() )
}
TEST( Test03, ScoreInstrument )
{
    TestMode v = TestMode::three;
	ScoreInstrumentPtr object = tgenScoreInstrument( v );
	stringstream expected;
	tgenScoreInstrumentExpected( expected, 1, v );
	stringstream actual;
	// object->toStream( std::cout, 1 );
	object->toStream( actual, 1 );
	CHECK_EQUAL( expected.str(), actual.str() )
	CHECK( object->hasAttributes() )
	CHECK( object->hasContents() )
}

namespace mxtest
{
    ScoreInstrumentPtr tgenScoreInstrument( TestMode v )
    {
        ScoreInstrumentPtr o = makeScoreInstrument();
        switch ( v )
        {
            case TestMode::one:
            {
                
            }
                break;
            case TestMode::two:
            {
                o->getInstrumentName()->setValue( XsString( "Bassoon" ) );
                o->setHasInstrumentAbbreviation( true );
                o->getInstrumentAbbreviation()->setValue( XsString( "Bsn." ) );
                o->setHasSoloOrEnsembleChoice( true );
                o->setHasVirtualInstrument( true );
                o->setVirtualInstrument( tgenVirtualInstrument( v ) );
                o->getAttributes()->id = XsID{ "Instrument01" };
                
            }
                break;
            case TestMode::three:
            {
                o->getInstrumentName()->setValue( XsString( "Trumpet" ) );
                o->setHasInstrumentAbbreviation( true );
                o->getInstrumentAbbreviation()->setValue( XsString( "Trp." ) );
                o->setHasSoloOrEnsembleChoice( true );
                o->getSoloOrEnsembleChoice()->setChoice( SoloOrEnsembleChoice::Choice::ensemble );
                PositiveIntegerOrEmpty forteen{ PositiveInteger{ 14 } };
                o->getSoloOrEnsembleChoice()->getEnsemble()->setValue( forteen );
                o->setHasVirtualInstrument( true );
                o->setVirtualInstrument( tgenVirtualInstrument( v ) );
                o->getAttributes()->id = XsID{ "Instrument02" };
            }
                break;
            default:
                break;
        }
        return o;
    }
    void tgenScoreInstrumentExpected(std::ostream& os, int i, TestMode v )
    {
        
        switch ( v )
        {
            case TestMode::one:
            {
                streamLine( os, i, R"(<score-instrument id="ID">)" );
                streamLine( os, i+1, R"(<instrument-name></instrument-name>)" );
                streamLine( os, i, R"(</score-instrument>)", false );
            }
                break;
            case TestMode::two:
            {
                streamLine( os, i, R"(<score-instrument id="Instrument01">)" );
                streamLine( os, i+1, R"(<instrument-name>Bassoon</instrument-name>)" );
                streamLine( os, i+1, R"(<instrument-abbreviation>Bsn.</instrument-abbreviation>)" );
                streamLine( os, i+1, R"(<solo/>)" );
                tgenVirtualInstrumentExpected( os, i+1, v );
                os << std::endl;
                streamLine( os, i, R"(</score-instrument>)", false );
            }
                break;
            case TestMode::three:
            {
                streamLine( os, i, R"(<score-instrument id="Instrument02">)" );
                streamLine( os, i+1, R"(<instrument-name>Trumpet</instrument-name>)" );
                streamLine( os, i+1, R"(<instrument-abbreviation>Trp.</instrument-abbreviation>)" );
                streamLine( os, i+1, R"(<ensemble>14</ensemble>)" );
                tgenVirtualInstrumentExpected( os, i+1, v );
                os << std::endl;
                streamLine( os, i, R"(</score-instrument>)", false );
            }
                break;
            default:
                break;
        }
    }
}

#endif
