;;--------------------------------------  
;;;;yasnippet-bundlesh设置  
(add-to-list 'load-path "/root/emacs")  
(require 'yasnippet-bundle)  
(setq yas/root-directory "/root/.emacs.d/plugins")  
;;--加入下面一段话会使加载时候很慢,可以Emacs启动后手动加载  M -x yas/load-director  
;;自己新建模板的话用yas/new-snippet  
;(yas/load-directory yas/root-directory)  
;;--------------------------------------  
;;-------------------------------------------------------------  
;;                  Auto complete  
;;-------------------------------------------------------------  
(add-to-list 'load-path "/root/emacs/auto-complete-1.3.1")  
(require 'auto-complete-config)  
(add-to-list 'ac-dictionary-directories "/root/emacs/auto-complete-1.3.1/ac-dict")  
(ac-config-default)  
(add-to-list 'load-path "/root/emacs/")  
(require 'gccsense)  
(global-set-key "\257" (quote ac-complete-gccsense))  
  
(add-hook 'c-mode-common-hook  
          (lambda ()  
            (flymake-mode)  
            (gccsense-flymake-setup)))  
  
(defun ac-complete-gccsense-self-insert (arg)  
  (interactive "p")  
  (self-insert-command arg)  
  (ac-complete-gccsense))  
(defun my-c-mode-ac-complete-hook ()  
  (local-set-key "." 'ac-complete-gccsense-self-insert)  
  (local-set-key ">" 'ac-complete-gccsense-self-insert))  
(add-hook 'c-mode-common-hook 'my-c-mode-ac-complete-hook)  
  
  
;;-----------------------------------------------------------------------  
;;加载主题插件;;;  
;;;M-x color-theme-select 回车  选择颜色  
;;-----------------------------------------------------------------------  
;(add-to-list 'load-path (expand-file-name "/root/.emacs.d/plugins"))      
;(require 'color-theme)    
;(color-theme-initialize)    
;(color-theme-gnome2)    
;(color-theme-billw)    
;(color-theme-gray30)    
;(color-theme-kingsajz)    
;(color-theme-tty-dark);;彩色黑色    
;(color-theme-midnight)    
  
(provide 'myplugin)  
