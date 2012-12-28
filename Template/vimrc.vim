au BufWritePre * sil %s/\s\+$//e "保存文件时自动删除行尾空格或Tab
au BufWritePre * %s/^$\n\+\%$//ge "删除文件尾多余的空行

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
set cindent
set showmatch
"set cursorline
"set nobackup
set nu

"定义CompileRun函数，用来调用进行编译和运行
func Compile()
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

func CompileRun()
	call Compile()
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
map <C-F9> :call Compile()<CR>
map <F9> :call CompileRun()<CR>
map <F8> :call Debug()<CR>

"set hlsearch "高亮显示搜索结果
set incsearch "查询时非常方便，如要查找book单词，当输入到/b时，会自动找到第一个b开头的单词，当输入到/bo时，会自动找到第一个bo开头的单词，依次类推，进行查找时，使用此设置会快速找到答案，当你找要匹配的单词时，别忘记回车



