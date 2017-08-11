/*
	Problem 59

	Each character on a computer is assigned a unique code and the preferred
	standard is ASCII (American Standard Code for Information Interchange).
	For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

	A modern encryption method is to take a text file, convert the bytes to
	ASCII, then XOR each byte with a given value, taken from a secret key.
	The advantage with the XOR function is that using the same encryption key
	on the cipher text, restores the plain text; for example, 65 XOR 42 = 107,
	then 107 XOR 42 = 65.

	For unbreakable encryption, the key is the same length as the plain text
	message, and the key is made up of random bytes. The user would keep the
	encrypted message and the encryption key in different locations, and without
	both "halves", it is impossible to decrypt the message.

	Unfortunately, this method is impractical for most users, so the modified
	method is to use a password as a key. If the password is shorter than the
	message, which is likely, the key is repeated cyclically throughout the
	message. The balance for this method is using a sufficiently long password
	key for security, but short enough to be memorable.

	Your task has been made easy, as the encryption key consists of three lower
	case characters. Using 0059.txt, a file containing the encrypted ASCII codes,
	and the knowledge that the plain text must contain common English words,
	decrypt the message and find the sum of the ASCII values in the original text.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "../timer.h"

int main()
{
	ProgramTimer timer;

	std::ifstream f("../_txt/0059.txt");
	if (!f.is_open())
		return 1;

	std::vector<char> text;
	while (f) {
		int x;
		f >> x;
		text.push_back(x);
	}

	f.close();

	char password[3];
	for (char c0 = 'a'; c0 <= 'z'; c0++) {
		password[0] = c0;
		for (char c1 = 'a'; c1 <= 'z'; c1++) {
			password[1] = c1;
			for (char c2 = 'a'; c2 <= 'z'; c2++) {
				password[2] = c2;
				std::string result = "";
				for (unsigned i = 0; i < text.size() - 1; i++)
					result += text[i] ^ password[i % 3];
				if (result.find(" the ") != std::string::npos) {
					unsigned ascii_sum = 0;
					for (char c : result)
						ascii_sum += c;
					std::cout << ascii_sum << '\n';
					timer.print_time();
					return 0;
				}
			}
		}
	}

	timer.print_time();
	return 0;
}

/*
	Solution:
	Avg time:
*/
