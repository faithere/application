(add-to-list 'load-path "/root/emacs")  
;;;;;;;;;;;;;缩进设置;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  
(defun my-c-mode-hook ()  
    (setq c-basic-offset 2  
          c-label-offset 0  
          indent-tabs-mode nil  
         ; compile-command "cd ~/projects/myproject; mvn compile"  
          require-final-newline nil)  
    (lambda () (auto-fill-mode 1))  
;    (define-key c-mode-base-map "C-m" 'c-context-line-break)  
  (c-set-offset 'substatement-open 0))  
  (add-hook 'c-mode-common-hook 'my-c-mode-hook)  
;;;;;;;;;;;;;缩进设置;;;;;;;;;;;;;;;;;;;;;;;;;  
  
;;改变默认的注释方式  
(defun my-c-comment ()  
      (interactive)  
      (insert "/**/")  
      (backward-char 2))  
(global-set-key (kbd "M-;") 'my-c-comment)  
  
;;-------------------------------------------------------------  
;;                      Cscope设置  
;;-------------------------------------------------------------  
(require 'xcscope)  
(add-hook 'c-mode-common-hook  
      '(lambda ()  
           (require 'xcscope) )  
      )  
(setq cscope-do-not-update-database t)  
;(define-key global-map (kbd "C-a")  'cscope-set-initial-directory)  
(define-key global-map [(control f4)]  'cscope-unset-initial-directory)  
(define-key global-map (kbd "M-f")  'cscope-find-this-symbol)  
(define-key global-map (kbd "M-g")  'cscope-find-global-definition)  
(define-key global-map (kbd "M-d")  'cscope-find-global-definition-no-prompting)  
(define-key global-map (kbd "M-p")  'cscope-pop-mark)  
(define-key global-map (kbd "M-n")  'cscope-next-symbol)  
(define-key global-map [(control f10)] 'cscope-next-file)  
(define-key global-map [(control f11)] 'cscope-prev-symbol)  
(define-key global-map [(control f12)] 'cscope-prev-file)  
(define-key global-map [(meta f9)]     'cscope-display-buffer)  
(define-key global-map [(meta f10)]    'cscope-display-buffer-toggle)  
  
;非交互式编译  
(defun do-compile ()  
  "Save buffers and start compile"  
  (interactive)  
  (save-some-buffers t)  
  (setq compilation-read-command nil)  
  (compile compile-command)  
  (setq compilation-read-command t))  
  
  
  
;;-------------------------------------------------------------  
;;;;;;;;;;;;;;;;;;;;;;GDB设置;;;;;;;;;;;;;;;;;;;;;;    
;;命令 功能   
;gdb 启动gdb进行调试   
;gdb-many-windows 切换单窗格/多窗格模式   
;gdb-restore-windows 恢复窗格布局   
  
;功能 命令 默认快捷键   
;添加断点 gud-break C-x C-a C-b 或 C-x <SPC>   
;删除断点 gud-remove C-x C-a C-d   
;运行/继续程序 gud-go 无   
;单步执行，无视函数 gud-next C-x C-a C-n   
;单步执行，进入函数 gud-step C-x C-a C-s   
;跳出当前函数 gud-finish C-x C-a C-f   
;运行到光标所在语句 gud-until C-x C-a C-u   
;继续运行程序 gud-cont C-x C-a C-r   
  
;功能 命令 默认快捷键   
;观察变量 gud-watch C-x C-a C-w   
;展开/收缩变量  <SPC>   
;开启/关闭工具提示 gud-tooltip-mode   
  
(global-set-key [f5] 'make-frame-command);;另外开启一个窗口进行gdb调试    
(setq gdb-many-windows t)    
(require 'gud)     
(global-set-key [f6] 'gdb)    
;;F5设置为在Emacs中调用gdb     
  
;shell,gdb退出后，自动关闭该buffer  
(add-hook 'shell-mode-hook 'mode-hook-func)  
(add-hook 'gdb-mode-hook 'mode-hook-func)  
(defun mode-hook-func  ()  
  (set-process-sentinel (get-buffer-process (current-buffer))  
         #'kill-buffer-on-exit))  
(defun kill-buffer-on-exit (process state)  
  (message "%s" state)  
  (if (or  
       (string-match "exited abnormally with code.*" state)  
       (string-match "finished" state))  
      (kill-buffer (current-buffer))))  
  
;;;;;;;;;;;;;;;;;;;;;END  GDB设置;;;;;;;;;;;;;;;;;;    
  
(provide 'c++conf)  

