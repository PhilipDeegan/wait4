

#include "kul/log.hpp"
#include "kul/proc.hpp"

int main(int argc, char* argv[]){
	short ec = 0;
	
	if(argc > 1){
		try{
			kul::Process p(argv[1]);
			for(uint i = 2; i < argc; i++) p.arg(argv[i]);
			p.start();
		}
		catch(const kul::proc::ExitException& e){ return e.code();}
		catch(const kul::Exception& e){ KERR << e.what(); return 2;}
		catch(const std::exception& e){ KERR << e.what(); return 3;}
		catch(...){ return 1; }
	}
	return 0;
}
