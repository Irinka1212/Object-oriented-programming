#include "MultimediaFile.h"
#include <iostream>

int main()
{
	MultimediaFile a("fff", 96, "ss");
	std::cout << a.getName() << " " << a.getSize() << " " << a.getExtension() << '\n';
	a.print_debug_state();

	a.setName("sss");
	a.setSize(32);
	a.setExtension("ff");

	a.print_debug_state();

	Audio b("dejavu", 44, "s", 34, "someone");
	std::cout << b.getName() << " " << b.getSize() << " " << b.getExtension() << " " << b.getLenght() << " " << b.getArtist() << '\n';
	b.print_debug_state();

	b.setArtist("olivia");
	b.setLenght(98);

	b.print_debug_state();

	Streaming c("ddddd", 49, "zzzz", "way");
	c.print_debug_state();

	MultimediaPlayer yes;
	yes.addFile(&a);
	yes.addFile(&b);
	yes.addFile(&c);

	yes.print_all_files_states(2);
	yes.print_all_files_states(1);
	yes.print_all_files_states(3);

	yes.removeFile(&c);
	std::system("pause");

	return 0;
}