ENTRY(_start)  /* 这是指定程序入口点的部分。它告诉链接器程序应该从 _start 标签处开始执行。*/
PHDRS { text PT_LOAD; data PT_LOAD; }  /* 这定义了程序头 (Program Headers) 的信息，指定了不同段的属性。text 和 data 段都被标记为 PT_LOAD，表示它们包含可加载的代码和数据。 */

/* 这部分定义了链接器如何组织不同的段。 */
SECTIONS {
  /* _pmem_start and _entry_offset are defined in LDFLAGS */
  . = _pmem_start + _entry_offset;    /* 这一行将链接器的当前位置设置为 _pmem_start 和 _entry_offset 的和。可执行程序重定位后的节从0x80000000开始 */
  .text : {
    /* 首先是.text节, 其中又以abstract-machine/am/src/$ISA/nemu/start.S中自定义的entry节开始, 然后接下来是其它目标文件的.text节. 这样, 可执行程序起始处总是放置start.S的代码, 而不是其它代码, 保证客户程序总能从start.S开始正确执行 */
    *(entry) /* 将 entry 部分的内容（程序的入口代码）复制到 .text 节中。*/
    *(.text*)  /* 将所有以 .text 开头的小节内容（通常是程序的代码）复制到 .text 节中。*/
  } : text
  etext = .;
  _etext = .;  /* etext = .; 和 _etext = .;：这两行定义了 etext 和 _etext 标签，它们表示 .text 节的末尾。 */
  .rodata : {  /* 它定义了只读数据段 */
    *(.rodata*)
  }
  .data : {
    *(.data)
  } : data
  edata = .;
  _data = .;
  .bss : {
	_bss_start = .;
    *(.bss*)
    *(.sbss*)
    *(.scommon)
  }
  _stack_top = ALIGN(0x1000); /* 栈顶位置 */
  . = _stack_top + 0x8000;
  _stack_pointer = .;
  end = .;
  _end = .;
  _heap_start = ALIGN(0x1000);
}
