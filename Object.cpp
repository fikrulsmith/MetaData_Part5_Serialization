#include "Precompiled.h"
#include "Object.h"

DEFINE_META( Object )
{
  ADD_MEMBER( ID );
  ADD_MEMBER( active );
  ADD_MEMBER( fire );
  ADD_MEMBER( x );
  ADD_MEMBER( test );
  ADD_MEMBER(fool);
}

Object::Object( int id ) : ID( id ), active( true ), x( 13.37 )
{
}

Object::~Object( )
{
}
