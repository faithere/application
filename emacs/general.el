(add-to-list 'load-path "/root/emacs")  
;; 括号匹配时显示另外一边的括号，而不是烦人的跳到另一个括号  
(show-paren-mode t)  
(setq show-paren-style 'parentheses)  
;关闭开机画面  
(setq inhibit-startup-message t)  
;; 不备份文件，不推荐  
(setq make-backup-files nil)  
;设置光标为竖线  
(setq-default cursor-type 'bar)  
;;标记开始  
(global-set-key (kbd "C-j") 'set-mark-command);;  
(tool-bar-mode 0)  
;;不要总是没完没了的问yes or no, 为什么不能用 y/n   
(fset 'yes-or-no-p 'y-or-n-p)   
;;;;;;;;;;;;;;;;;;;;;;;;;;;;   显示时间设置   ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;  
(display-time-mode 1);;启用时间显示设置，在minibuffer上面的那个杠上  
(setq display-time-24hr-format t);;时间使用24小时制  
(setq display-time-day-and-date t);;时间显示包括日期和具体时间  
(setq display-time-use-mail-icon t);;时间栏旁边启用邮件设置  
(setq display-time-interval 10);;时间的变化频率，单位多少来着？  
   
;;;;;;;;;;;;;;;;;;;;;;;;;;;  显示时间设置结束  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;   
(customize-set-variable 'scroll-bar-mode 'right)   
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;END常规设置;;;;;;;;;;;;;;;  
  
;;-------------------------------------------------------------  
;;                  ;;显示行号  
;;-------------------------------------------------------------  
(global-linum-mode 1)  
(require 'setnu)  
(setnu-mode t)  
;;-------------------------------------------------------------  
;;                  Tabbar 设置  
;;-------------------------------------------------------------  
  
(require 'tabbar)  
(tabbar-mode)  
(global-set-key [(meta j)] 'tabbar-backward)    
(global-set-key [(meta k)] 'tabbar-forward)  
;;;; 设置tabbar外观   
;; 设置默认主题: 字体, 背景和前景颜色，大小   
(set-face-attribute 'tabbar-default nil  
                    :family "Vera Sans YuanTi Mono"  
                    :background "gray80"  
                    :foreground "gray30"  
                    :height 1.0   
                    )   
;; 设置左边按钮外观：外框框边大小和颜色   
(set-face-attribute 'tabbar-button nil  
                    :inherit 'tabbar-default  
                    :box '(:line-width 1 :color "gray30")   
                    )   
;; 设置当前tab外观：颜色，字体，外框大小和颜色   
(set-face-attribute 'tabbar-selected nil  
                    :inherit 'tabbar-default  
                    :foreground "DarkGreen"  
                    :background "LightGoldenrod"  
                    :box '(:line-width 2 :color "DarkGoldenrod")   
                    ;; :overline "black"   
                    ;; :underline "black"   
                    :weight 'bold  
                    )   
;; 设置非当前tab外观：外框大小和颜色   
(set-face-attribute 'tabbar-unselected nil  
                    :inherit 'tabbar-default  
                    :box '(:line-width 2 :color "gray70")   
                    )  
  
(provide 'general)  

