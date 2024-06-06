call plug#begin('~/.vim/plugged')
call plug#end()

call plug#begin()
Plug 'preservim/nerdtree'
Plug 'itchyny/lightline.vim'
Plug 'Yggdroot/LeaderF', { 'do': ':LeaderfInstallCExtension' }
Plug 'Valloric/YouCompleteMe'
Plug 'luochen1990/rainbow'
Plug 'tpope/vim-fugitive'
Plug 'preservim/nerdcommenter'
call plug#end()
map <C-n> :NERDTreeToggle<CR>
let g:ycm_global_ycm_extra_conf = '~/.vim/plugged/YouCompleteMe/third_party/ycmd/.ycm_extra_conf.py'
let g:lightline = {
      \ 'colorscheme': 'one',
      \ 'active': {
      \   'left': [ [ 'mode', 'paste' ],
      \             [ 'gitbranch', 'readonly', 'filename', 'diy' ] ]
      \ },
      \ 'component_function': {
      \   'gitbranch': 'FugitiveHead'
      \ },
	  \ 'component': {
      \  'diy': 'Hello, world!'
      \ },
      \ }

let g:Lf_ShortcutF = '<c-p>'
let g:Lf_ShowDevIcons = 0
let g:Lf_WorkingDirectoryMode = 'AF'
let g:Lf_RootMarkers = ['.git', '.svn', '.hg', '.project', '.root']
let g:Lf_DefaultExternalTool='rg'
let g:Lf_PreviewInPopup = 1

set nocompatible
syntax on

set shortmess+=I

set number

set relativenumber

set laststatus=2

set backspace=indent,eol,start

set hidden

set ignorecase
set smartcase

set incsearch

set nobackup
set noswapfile

nmap Q <Nop> " 'Q' in normal mode enters Ex mode. You almost never want this.

set noerrorbells visualbell t_vb=

set mouse+=a
set mouse=r

nnoremap <Left>  :echoe "Use h"<CR>
nnoremap <Right> :echoe "Use l"<CR>
nnoremap <Up>    :echoe "Use k"<CR>
nnoremap <Down>  :echoe "Use j"<CR>

map <C-A> ggVGY
map! <C-A> <Esc>ggVGY
map <F12> gg=G
vmap <C-c> "+y

imap jj <Esc>
im <C-d> <Left>
im <C-f> <right>
set tabstop=4
set softtabstop=4
set shiftwidth=4
set smartindent
set smarttab

inoremap ( ()<ESC>i
inoremap ) <c-r>=ClosePair(')')<CR>
inoremap { {}<ESC>i
inoremap {<CR> {<CR>}<ESC>O
inoremap } <c-r>=ClosePair('}')<CR>
inoremap [ []<ESC>i
inoremap ] <c-r>=ClosePair(']')<CR>
inoremap " ""<ESC>i
inoremap ' ''<ESC>i
nmap oo o<Esc>
function! ClosePair(char)

    if getline('.')[col('.') - 1] == a:char

        return "\<Right>"

    else

        return a:char

    endif

endfunction

filetype plugin indent on 
set completeopt=longest,menu

map <F8> :call Rungdb()<CR>

func! Rungdb()

    exec "w"

    exec "!g++ % -g -o %<"

    exec "!gdb ./%<"

endfunc

map <F5> :call CompileRunGcc()<CR>

func! CompileRunGcc()

    exec "w"

    if &filetype == 'c'

        exec "!g++ % -o %<"

        exec "! ./%<"

    elseif &filetype == 'cpp'

        exec "!g++ % -o %<"

        exec "! ./%<"

    elseif &filetype == 'java'

        exec "!javac %"

        exec "!java %<"

    elseif &filetype == 'sh'

        :!./%

    endif

endfunc
