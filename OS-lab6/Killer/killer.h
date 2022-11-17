#ifndef KILLER_H
#define KILLER_H

#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include <string>
#include <locale>
#include <codecvt>
#include <iostream>

void KillProcessByName(const char *filename);
void KillProcessByID(INT32 id);
void KillProcessByEV();

#endif