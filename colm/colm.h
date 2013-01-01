#ifndef __COLM_COLM_H
#define __COLM_COLM_H

#ifdef __cplusplus
extern "C" {
#endif

struct ColmTree;
struct ColmKid;
struct ColmProgram;
struct ColmRuntimeData;

void colmInit( long debugRealm );
struct ColmProgram *colmNewProgram( struct ColmRuntimeData *rtd );
void colmRunProgram( struct ColmProgram *prg, int argc, const char **argv );
int colmDeleteProgram( struct ColmProgram *prg );

struct ColmPrintArgs
{
	void *arg;
	int comm;
	int attr;
	int trim;
	void (*out)( struct ColmPrintArgs *args, const char *data, int length );
	void (*openTree)( struct ColmProgram *prg, struct ColmTree **sp, 
		struct ColmPrintArgs *args, struct ColmKid *parent, struct ColmKid *kid );
	void (*printTerm)( struct ColmProgram *prg, struct ColmTree **sp, 
		struct ColmPrintArgs *args, struct ColmKid *kid );
	void (*closeTree)( struct ColmProgram *prg, struct ColmTree **sp, 
		struct ColmPrintArgs *args, struct ColmKid *parent, struct ColmKid *kid );
};

void printNull( struct ColmProgram *prg, struct ColmTree **sp,
		struct ColmPrintArgs *args, struct ColmKid *parent, struct ColmKid *kid );
void printTermTree( struct ColmProgram *prg, struct ColmTree **sp,
		struct ColmPrintArgs *printArgs, struct ColmKid *kid );

struct ColmTree **vm_root( struct ColmProgram *prg );
struct ColmTree *returnVal( struct ColmProgram *prg );
void printTreeArgs( struct ColmProgram *prg, struct ColmTree **sp,
		struct ColmPrintArgs *printArgs, struct ColmTree *tree );

int repeatEnd( struct ColmTree *tree );
int listLast( struct ColmTree *tree );
struct ColmTree *getRhsVal( struct ColmProgram *prg, struct ColmTree *tree, int *a );
struct ColmTree *getAttr( struct ColmTree *tree, long pos );
struct ColmTree *getGlobal( struct ColmProgram *prg, long pos );
struct ColmTree *getRepeatNext( struct ColmTree *tree );
struct ColmTree *getRepeatVal( struct ColmTree *tree );

#ifdef __cplusplus
}
#endif

#endif