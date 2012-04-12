#include "Process.hpp"
#include <unistd.h>
#include <sys/wait.h>


Process::Process( const std::vector<char*>& vect, bool verbose )
{

	
	this->verbose = verbose;

	int size = vect.size();
	char* argv[size];
	for( int i = 0; i < size; ++i )
		argv[i] = vect[i];

	m_pid = fork();
	
	switch(m_pid)
	{
		case -1:
			std::cerr << "Cannot fork." << std::endl;
			break;
		case 0:
			
			execvp( argv[0], argv );
			std::cerr << "Did not execute." << std::endl;
			break;
		default:
			break;
	}

}


Process::~Process()
{
	pid_t pid = 0;
	while( pid != m_pid )
		pid = waitpid( pid, &m_status, 0 );
}
