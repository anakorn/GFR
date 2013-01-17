#include "InputMgr.h"
#include "Common.h"
#include "allegro5\allegro.h"

using namespace framework;

typedef struct
{
	const char* name;
	const u32 num;
	u32 binding;
} keyName;

#define NAME_KEY(name) { #name, ALLEGRO_KEY_##name, ALLEGRO_KEY_##name }

keyName keyNames[] = 
{
	{ "NULL", 0, 0 },
	NAME_KEY( A ),
	NAME_KEY( B ),
	NAME_KEY( C ),
	NAME_KEY( D ),
	NAME_KEY( E ),
	NAME_KEY( F ),
	NAME_KEY( G ),
	NAME_KEY( H ),
	NAME_KEY( I ),
	NAME_KEY( J ),
	NAME_KEY( K ),
	NAME_KEY( L ),
	NAME_KEY( M ),
	NAME_KEY( N ),
	NAME_KEY( O ),
	NAME_KEY( P ),
	NAME_KEY( Q ),
	NAME_KEY( R ),
	NAME_KEY( S ),
	NAME_KEY( T ),
	NAME_KEY( U ),
	NAME_KEY( V ),
	NAME_KEY( W ),
	NAME_KEY( X ),
	NAME_KEY( Y ),
	NAME_KEY( Z ),
	NAME_KEY( 0 ),
	NAME_KEY( 1 ),
	NAME_KEY( 2 ),
	NAME_KEY( 3 ),
	NAME_KEY( 4 ),
	NAME_KEY( 5 ),
	NAME_KEY( 6 ),
	NAME_KEY( 7 ),
	NAME_KEY( 8 ),
	NAME_KEY( 9 ),
	NAME_KEY( PAD_0 ),
	NAME_KEY( PAD_1 ),
	NAME_KEY( PAD_2 ),
	NAME_KEY( PAD_3 ),
	NAME_KEY( PAD_4 ),
	NAME_KEY( PAD_5 ),
	NAME_KEY( PAD_6 ),
	NAME_KEY( PAD_7 ),
	NAME_KEY( PAD_8 ),
	NAME_KEY( PAD_9 ),
	NAME_KEY( F1 ),
	NAME_KEY( F2 ),
	NAME_KEY( F3 ),
	NAME_KEY( F4 ),
	NAME_KEY( F5 ),
	NAME_KEY( F6 ),
	NAME_KEY( F7 ),
	NAME_KEY( F8 ),
	NAME_KEY( F9 ),
	NAME_KEY( F10 ),
	NAME_KEY( F11 ),
	NAME_KEY( F12 ),
	NAME_KEY( ESCAPE ),
	NAME_KEY( TILDE ),
	NAME_KEY( MINUS ),
	NAME_KEY( EQUALS ),
	NAME_KEY( BACKSPACE ),
	NAME_KEY( TAB ),
	NAME_KEY( OPENBRACE ),
	NAME_KEY( CLOSEBRACE ),
	NAME_KEY( ENTER ),
	NAME_KEY( SEMICOLON ),
	NAME_KEY( QUOTE ),
	NAME_KEY( BACKSLASH ),
	NAME_KEY( BACKSLASH2 ),
	NAME_KEY( COMMA ),
	NAME_KEY( FULLSTOP ),
	NAME_KEY( SLASH ),
	NAME_KEY( SPACE ),
	NAME_KEY( INSERT ),
	{ "DELETE", ALLEGRO_KEY_DELETE, ALLEGRO_KEY_DELETE },
	NAME_KEY( HOME ),
	NAME_KEY( END ),
	NAME_KEY( PGUP ),
	NAME_KEY( PGDN ),
	NAME_KEY( LEFT ),
	NAME_KEY( RIGHT ),
	NAME_KEY( UP ),
	NAME_KEY( DOWN ),
	NAME_KEY( PAD_SLASH ),
	NAME_KEY( PAD_ASTERISK ),
	NAME_KEY( PAD_MINUS ),
	NAME_KEY( PAD_PLUS ),
	NAME_KEY( PAD_DELETE ),
	NAME_KEY( PAD_ENTER ),
	NAME_KEY( PRINTSCREEN ),
	NAME_KEY( PAUSE ),
	NAME_KEY( ABNT_C1 ),
	NAME_KEY( YEN ),
	NAME_KEY( KANA ),
	NAME_KEY( CONVERT ),
	NAME_KEY( NOCONVERT ),
	NAME_KEY( AT ),
	NAME_KEY( CIRCUMFLEX ),
	NAME_KEY( COLON2 ),
	NAME_KEY( KANJI ),
	NAME_KEY( PAD_EQUALS ),
	NAME_KEY( BACKQUOTE ),
	NAME_KEY( SEMICOLON2 ),
	NAME_KEY( COMMAND ),
	NAME_KEY( UNKNOWN ),

	/* All codes up to before ALLEGRO_KEY_MODIFIERS (215) can be freely
	* assigned additional unknown keys, like various multimedia
	* and application keys keyboards may have.
	*/

	/*NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),
	NAME_KEY( 0 ),*/
	NAME_KEY( MAX )
};

bool InputMgr::Initialize(ALLEGRO_EVENT_QUEUE* queue)
{
	bool keyboardInstalled = al_install_keyboard();
	bool mouseInstalled = al_install_mouse();

	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());

	return keyboardInstalled && mouseInstalled;
}

void InputMgr::Update(void)
{
	
}

bool InputMgr::IsDown(const u32 keyNum)
{


	return false;
}

void InputMgr::BindKey(const u32 keyNum, const u32 keyBind)
{
	// Cannot trust the user to bind a valid key
	assert(keyBind >= ALLEGRO_KEY_A && keyBind < 108);

	//TODO: uncomment after naming keys between 108 and ALLEGRO_KEY_MAX
	//assert(keyBind >= ALLEGRO_KEY_A && keyBind < ALLEGRO_KEY_MAX);

	keyNames[keyNum].binding = keyBind;
}

const char* GetBoundKeyName(const u32 keyNum)
{
	return "IMPLEMENT THIS FUNCTION";
	//return keyNames[keyNum].
}