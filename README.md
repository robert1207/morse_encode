# morse-encode-and-decode

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/4781e30bba254e4da7ec8373234718d9)](https://app.codacy.com/gh/Joker2770/morse-encode-and-decode?utm_source=github.com&utm_medium=referral&utm_content=Joker2770/morse-encode-and-decode&utm_campaign=Badge_Grade_Settings)

morse encode and decode

## Build
Required:
* make
* gcc

Step:
~~~
git clone https://github.com/Joker2770/morse-encode-and-decode.git
cd morse-encode-and-decode
make
./morse-encode-and-decode
sudo make install
morse-encode-and-decode
~~~

## Usage

**morse-encode-and-decode -l** <br>
**morse-encode-and-decode {-e|-d} {\<string\>}** <br>

~~~

	--list   (-l)	List morse code table.

	--encode (-e)	Encode string. e.g.: morse-encode-and-decode -e "Hello world!"

	--decode (-d)	Decode Morse code. e.g.: morse-encode-and-decode -d ".- -... -.-. "
	
~~~