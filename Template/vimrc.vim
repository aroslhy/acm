"设置深色主题
colorscheme evening
"隐藏工具栏
"set guioptions-=T

"设置C/C++语言的具体缩进方式
"set cinoptions={0,1s,t0,n-2,p2s,(03s,=.5s,>1s,=1s,:1s
"set smartindent
"set expandtab "使用空格代替tab.
set ts=4 "空格数量
set shiftwidth=4 "自动缩进的宽度
set showmatch
set cursorline
"set nobackup
set nu

"定义CompileRun函数，用来调用进行编译和运行
func CompileRun()
	exec "w"
	"C程序
	if &filetype == 'c'
		exec "!gcc -Wall -enable-auto-import % -g -o %<"
	"c++程序
	elseif &filetype == 'cpp' || &filetype == 'cc'
		exec "!g++ % -g -o %<"
	"Java程序
	elseif &filetype == 'java'
		exec "!javac %"
	endif
endfunc
"结束定义CompileRun

"定义Run函数
func Run()
	if &filetype == 'c' || &filetype == 'cpp' || &filetype == 'cc'
		exec "!./%<"
	elseif &filetype == 'java'
		exec "!java %<"
	endif
endfunc

"定义Debug函数，用来调试程序
func Debug()
	exec "w"
	"C程序
	if &filetype == 'c'
		exec "!gcc % -g -o %<"
		exec "!gdb %<"
	elseif &filetype == 'cpp' || &filetype == 'cc'
		exec "!g++ % -g -o %<"
		exec "!gdb %<"
	"Java程序
	elseif &filetype == 'java'
		exec "!javac %"
		exec "!jdb %<"
	endif
endfunc
"结束定义Debug

"设置程序的编译，运行,调试的快捷键
map <C-F9> :call CompileRun()<CR>
map <F9> :call Run()<CR>
"map <F7> :call Debug()<CR>
"单选注释
":map <C-q> <Esc>^i//<Esc>
"取消单选注释
":map <C-w> <Esc>^df/<Esc>

