#pragma once

//int g_global = 0;	// 일반 전역변수를 포함한 헤더파일을 여러 cpp 파일에서 #include 하면 오류남
// => 해결 : 외부변수 선언 (전역변수를 다른 파일에 연결 가능)
extern int e_global;