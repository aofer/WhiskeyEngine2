#define WE_ROOT_NAMESPACE WhiskeyEngine

#define NAMESPACE_BEGIN(name) namespace WE_ROOT_NAMESPACE { namespace name {
#define NAMESPACE_END }}
#define NAMESPACE_BEGIN2(name1,name2) namespace WE_ROOT_NAMESPACE { namespace name1 { namespace name2 {
#define NAMESPACE_END2 }}}

#define SAFE_DELETE(a) if( (a) != NULL ) delete (a); (a) = NULL;

#define INVALID_GL_VALUE 0xffffffff
#define INVALID_UNIFORM_LOCATION 0xffffffff

#define GLCheckError() (glGetError() == GL_NO_ERROR)
#define GLCheckError2() glGetError()

#define ARRAY_SIZE_IN_ELEMENTS(a) (sizeof(a)/sizeof(a[0]))

typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
#define SNPRINTF _snprintf_s