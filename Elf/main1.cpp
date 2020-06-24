#include "Elf.h"
#include "ElfTeam.h"

#include <vector>

using namespace std;

int main()
{
	Elf elr( "Elrond", 200, 10 );
	Elf arw( "Arwen", 50, 5 );
	Elf gal( "Galadriel", 300, 15 );
	Elf cel( "Celeborn", 300, 10 );

	ElfTeam riv( "Rivendell" );
	riv.AddElf( elr );
	riv.AddElf( arw );

	ElfTeam lot( "Lothlorien" );
	lot.AddElf( gal );
	lot.AddElf( cel );

	cout << boolalpha << riv.GetName() << " is weaker than " << lot.GetName() << ": " << ( riv < lot ) << endl;

	lot.RemoveElf( "Celeborn" );

	cout << boolalpha << riv.GetName() << " is weaker than " << lot.GetName() << ": " << ( riv < lot ) << endl;

	Elf thr( "Thranduil", 200, 11 );

	ElfTeam woo( "Woodland Realm" );
	woo.AddElf( thr );

	cout << boolalpha << riv.GetName() << " is weaker than " << woo.GetName() << ": " << ( riv < woo ) << endl;
	cout << boolalpha << woo.GetName() << " is weaker than " << lot.GetName() << ": " << ( woo < lot ) << endl;
	cout << boolalpha << woo.GetName() << " is weaker than " << riv.GetName() << ": " << ( woo < riv ) << endl;

	vector<ElfTeam> teams { riv, lot, woo };

	analyze( teams );

	cin.get();
}