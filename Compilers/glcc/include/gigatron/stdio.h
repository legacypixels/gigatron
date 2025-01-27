#ifndef __STDIO
#define __STDIO

#define _IOFBF   0x40  /* fully buffered */
#define _IOLBF   0xC0  /* line buffered. */
#define _IONBF   0x80  /* not buffered   */
#define _IOMYBUF 0x20  /* own buffer     */
#define _IOSTR   0x10  /* sprintf/scanf  */
#define	_IOEOF   0x08  /* eof flag       */
#define	_IOERR   0x04  /* error flag     */
#define _IORW    0x03  /* r+,w+,a+       */
#define _IOREAD  0x01  /* r              */
#define _IOWRIT  0x02  /* w,a            */
#define _IOBUFMASK 0xE0
#define _IOMODMASK 0x03

#define BUFSIZ 80
#define EOF    (-1)

extern struct _iobuf {
	int  _cnt;
	char *_ptr;
	int  _flag;
	int  _file;
	char _buf[4];
	struct _sbuf *_base;
	struct _svec *_v;
} _iob[];

#define FILE struct _iobuf
#define FILENAME_MAX 256
#define FOPEN_MAX 10

#if !defined(_FPOS_T) && !defined(_FPOS_T_) && !defined(_FPOS_T_DEFINED)
#define _FPOS_T
#define _FPOS_T_
#define _FPOS_T_DEFINED
typedef long fpos_t;
#endif

#define L_tmpnam 25
#ifndef NULL
#define NULL ((void*)0)
#endif
#define SEEK_CUR 1
#define SEEK_END 2
#define SEEK_SET 0

#if !defined(_SIZE_T) && !defined(_SIZE_T_) && !defined(_SIZE_T_DEFINED)
#define _SIZE_T
#define _SIZE_T_
#define _SIZE_T_DEFINED
typedef unsigned int size_t;
#endif

#if !defined(_VA_LIST) && !defined(_VA_LIST_DEFINED)
#define _VA_LIST
#define _VA_LIST_DEFINED
typedef char *__va_list;
#endif

#define stderr (&_iob[2])
#define stdin  (&_iob[0])
#define stdout (&_iob[1])
#define TMP_MAX 17576

extern int remove(const char *);
extern int rename(const char *, const char *);
extern FILE *tmpfile(void);
extern char *tmpnam(char *);
extern int fclose(FILE *);
extern int fflush(FILE *);
extern FILE *fopen(const char *, const char *);
extern FILE *freopen(const char *, const char *, FILE *);
extern void setbuf(FILE *, char *);
extern int setvbuf(FILE *, char *, int, size_t);
extern int fprintf(FILE *, const char *, ...);
extern int fscanf(FILE *, const char *, ...);
extern int printf(const char *, ...);
extern int scanf(const char *, ...);
extern int sprintf(char *, const char *, ...);
extern int sscanf(const char *, const char *, ...);
extern int vfprintf(FILE *, const char *, __va_list);
extern int vprintf(const char *, __va_list);
extern int vsprintf(char *, const char *, __va_list);
extern int fgetc(FILE *);
extern char *fgets(char *, int, FILE *);
extern int fputc(int, FILE *);
extern int fputs(const char *, FILE *);
extern int getc(FILE *);
extern int getchar(void);
extern char *gets(char *);
extern int putc(int, FILE *);
extern int putchar(int);
extern int puts(const char *);
extern int ungetc(int, FILE *);
extern size_t fread(void *, size_t, size_t, FILE *);
extern size_t fwrite(const void *, size_t, size_t, FILE *);
extern int fgetpos(FILE *, fpos_t *);
extern int fseek(FILE *, long int, int);
extern int fsetpos(FILE *, const fpos_t *);
extern long int ftell(FILE *);
extern void rewind(FILE *);
extern void clearerr(FILE *);
extern int feof(FILE *);
extern int ferror(FILE *);
extern void perror(const char *);

#define getc(p) (--(p)->_cnt < 0 ? _filbuf(p) : (int) *(p)->_ptr++)
#define putc(x, p) (--(p)->_cnt < 0 ? _flsbuf((char)(x),p) : (int)(*(p)->_ptr++=(char)(x)))
#define getchar() (getc(stdin))
#define putchar(x) (putc(x,stdout))
#define ferror(p) ((p)->_flag & _IOERR)
#define feof(p) ((p)->_flag & _IOEOF)
#define clearerr(p) ((p)->_flag &= (_IOERR|_IOEOF)^0xff)

extern int _filbuf(FILE *);
extern int _flsbuf(int, FILE *);

#endif /* __STDIO */
