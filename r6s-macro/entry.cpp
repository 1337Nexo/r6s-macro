#include <windows.h>
#include <iostream>
#include <time.h>
#include <random>
#include <future>

#include "xorstr.hpp"

double random_numbers( double x, double y )
{
	std::random_device rd;
	std::mt19937 gen( rd( ) );
	std::uniform_real_distribution<> dist( x, y );

	return dist( gen );
}

bool main( )
{
	static int choice;
	static double rand;

	SetConsoleTitle( xorstr("[+]: r6s-macro") );

	std::cout << xorstr( "[+]: a simple software that emulates mouse movements" ) << std::endl;
	std::cout << xorstr( "[+]: made for educational purposes only" ) << std::endl;
	std::cout << xorstr( "[+]: end key is panic key" ) << std::endl << std::endl;
	std::cout << xorstr( "[0]: legit mode" ) << std::endl;
	std::cout << xorstr( "[1]: blatant mode" ) << std::endl;
	std::cout << xorstr( "[2]: rage mode" ) << std::endl;
	std::cout << xorstr("> ");
	std::cin >> choice;
	std::cout << std::endl;

	if (choice > 2 || choice < 0)
		return false;

	switch (choice)
	{
	case 0:
		std::cout << xorstr( "[+] running legit mode" ) << std::endl << std::endl;
		break;
	case 1:
		std::cout << xorstr( "[+] running blatant mode" ) << std::endl << std::endl;
		break;
	case 2:
		std::cout << xorstr( "[+] running rage mode" ) << std::endl << std::endl;
		break;
	}

	while (!GetAsyncKeyState( VK_END ))
	{
		if (GetAsyncKeyState( VK_LBUTTON ) & ~32767)
		{
			switch (choice)
			{
			case 0:
				rand = random_numbers( 2.0, 4.0 );
				std::cout << rand << xorstr( " " );
				std::this_thread::sleep_for( std::chrono::milliseconds( 14 ) );
				mouse_event( MOUSEEVENTF_MOVE, -rand, -rand, NULL, NULL );
				std::this_thread::sleep_for( std::chrono::milliseconds( 17 ) );
				mouse_event( MOUSEEVENTF_MOVE, rand, rand, NULL, NULL );
				break;
			case 1:
				rand = random_numbers( 5.0, 6.0 );
				std::cout << rand << xorstr(" ");
				mouse_event( MOUSEEVENTF_MOVE, NULL, NULL, NULL, NULL );
				std::this_thread::sleep_for( std::chrono::milliseconds( 0 ) );
				mouse_event( MOUSEEVENTF_MOVE, rand, -rand, NULL, NULL );
				std::this_thread::sleep_for( std::chrono::milliseconds( 12 ) );
				mouse_event( MOUSEEVENTF_MOVE, -rand, rand, NULL, NULL );
				std::this_thread::sleep_for( std::chrono::milliseconds( 12 ) );
				mouse_event( MOUSEEVENTF_MOVE, -rand, -rand, NULL, NULL );
				std::this_thread::sleep_for( std::chrono::milliseconds( 12 ) );
				mouse_event( MOUSEEVENTF_MOVE, rand, rand, NULL, NULL );
				break;
			case 2:
				rand = random_numbers( 10.0, 12.0 );
				std::cout << rand << xorstr( " " );	
				std::this_thread::sleep_for( std::chrono::milliseconds( 15 ) );
				mouse_event( MOUSEEVENTF_MOVE, NULL, NULL, NULL, NULL );
				std::this_thread::sleep_for( std::chrono::milliseconds( 15 ) );
				mouse_event( MOUSEEVENTF_MOVE, NULL, NULL, NULL, NULL );
				std::this_thread::sleep_for( std::chrono::milliseconds( 15 ) );
				mouse_event( MOUSEEVENTF_MOVE, rand, rand, NULL, NULL );
				std::this_thread::sleep_for( std::chrono::milliseconds( 15 ) );
				mouse_event( MOUSEEVENTF_MOVE, -rand, -rand, NULL, NULL );
				break;
			}
		}
	}

	std::this_thread::sleep_for( std::chrono::milliseconds( 50 ) );

	return false;
}