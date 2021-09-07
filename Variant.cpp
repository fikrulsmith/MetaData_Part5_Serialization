#include "Precompiled.h"

Variant::Variant( const MetaData *m, void *d ) : VariantBase( m, d )
{
}

Variant::Variant( ) : VariantBase( NULL, NULL )
{
}

Variant& Variant::operator=( const Variant& rhs )
{
  if(this == &rhs)
    return *this;

  if(meta)
  {
    if(meta == rhs.meta)
      meta->Copy( data, rhs.data );
    else
    {
      assert( rhs.meta ); // Cannot make an instance of NULL meta!

      meta->Delete( data );
      meta = rhs.Meta( );

      // We require a new copy if meta does not match!
      if(meta)
        data = meta->NewCopy( &rhs.data );
    }
  }

  return *this;
}
