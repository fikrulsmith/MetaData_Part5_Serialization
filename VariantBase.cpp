#include "Precompiled.h"
#include "VariantBase.h"

VariantBase::VariantBase( ) : meta( NULL ), data( NULL )
{
}

VariantBase::VariantBase( const MetaData* meta, void* data ) : meta( meta ), data( data )
{
}

const MetaData *VariantBase::Meta( void ) const
{
  return meta;
}

void VariantBase::Serialize( std::ostream& os ) const
{
  meta->Serialize( os, RefVariant( meta, data ) );
}

void *VariantBase::Data( void ) const
{
  return data;
}
