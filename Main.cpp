#include "Precompiled.h"
#include "Object.h"
#include "Vector.h"

DEFINE_META_POD( int );
DEFINE_META_POD( int * );
DEFINE_META_POD( char );
DEFINE_META_POD( char * );
DEFINE_META_POD( float );
DEFINE_META_POD( bool );
DEFINE_META_POD( double );
DEFINE_META_POD( std::string );
DEFINE_META_POD( Test );

void main( void )
{
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
  int x = 5;
  
  RefVariant refv;

  refv = x;

  const char *c = "String";
  
  Variant v = c;

  refv = v;

  v.Serialize( std::cout );

  Object ob( 14 );

  RefVariant object = ob;
  //std::cout << object.Meta()->Members()->Name() << std::endl;
  object.Serialize( std::cout );
  //std::cout << object.GetValue<int>();

  Test2 flu = Test2::test22;
  std::string fuck = "Test         2";
  std::cout << lexical_cast_toStr<Test2>(flu);
  std::cout << static_cast<int>(lexical_cast_toEnum<Test2>(fuck));
}
