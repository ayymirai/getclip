/*
	getclip - Reads text from clipboard and outputs it to stdout
    Copyright (C) >2017 Mirai

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef WIN32
#error This program was designed to be compiled for Win32.
#endif

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winnt.h>

int read_clipboard();

int main(int argc, char **argv){
	if (read_clipboard()){
		return 1;
	}	
	return 0;
}

int read_clipboard(){
	UINT dtFormat=CF_TEXT;
	HANDLE h;
	int i=0;
	if (OpenClipboard(NULL)){
		h = GetClipboardData(dtFormat);
		CloseClipboard();	//must call ASAP after a successful clipboard open
		if (h!=INVALID_HANDLE_VALUE && h!=NULL){ 
		printf("%s", h);
		}
		return 0;
	} else {
		return 1;
	}
	return 1; //should never reach this point
}
