/** @file src/file.h %File access definitions. */

#ifndef FILE_H
#define FILE_H

#include <stdio.h>

enum {
	FILEINFO_MAX     = 686,
	FILEINFO_INVALID = 0xFFFF,

	FILE_MAX = 20,
	FILE_INVALID = 0xFF
};

enum SearchDirectory {
	SEARCHDIR_ABSOLUTE,
	SEARCHDIR_GLOBAL_DATA_DIR,
	SEARCHDIR_CAMPAIGN_DIR,
	SEARCHDIR_PERSONAL_DATA_DIR
};

/**
 * Static information about files and their location.
 */
typedef struct FileInfo {
	const char *filename;                                   /*!< Name of the file. */
	uint32 fileSize;                                        /*!< The size of this file. */
	void *buffer;                                           /*!< In case the file is read in the memory, this is the location of the data. */
	uint32 filePosition;                                    /*!< Where in the file we currently are (doesn't have to start at zero when in PAK file). */
	uint16 parentIndex;                                     /*!< In which FileInfo this file can be found. */
	struct {
		BIT_U8 isLoaded:1;                                  /*!< File is mapped in the memory. */
		BIT_U8 inMemory:1;                                  /*!< File is loaded in alloc'd memory. */
		BIT_U8 inPAKFile:1;                                 /*!< File can be in other PAK file. */
	} flags;                                                /*!< General flags of the FileInfo. */
} FileInfo;

extern char g_dune_data_dir[1024];
extern char g_personal_data_dir[1024];

extern void FileHash_Init(void);
extern FileInfo *FileHash_Store(const char *key);
extern unsigned int FileHash_FindIndex(const char *key);

extern FILE *File_Open_CaseInsensitive(enum SearchDirectory dir, const char *filename, const char *mode);
extern void File_Close(uint8 index);
extern uint32 File_Read(uint8 index, void *buffer, uint32 length);
extern uint32 File_Write(uint8 index, void *buffer, uint32 length);
extern uint32 File_Seek(uint8 index, uint32 position, uint8 mode);
extern uint32 File_GetSize(uint8 index);
extern void File_Delete_Personal(const char *filename);
extern void ChunkFile_Close(uint8 index);
extern uint32 ChunkFile_Seek(uint8 index, uint32 header);
extern uint32 ChunkFile_Read(uint8 index, uint32 header, void *buffer, uint32 buflen);

#define File_Exists(FILENAME)               File_Exists_Ex(SEARCHDIR_GLOBAL_DATA_DIR,   FILENAME)
#define File_Exists_Personal(FILENAME)      File_Exists_Ex(SEARCHDIR_PERSONAL_DATA_DIR, FILENAME)
#define File_Open(FILENAME,MODE)            File_Open_Ex(SEARCHDIR_GLOBAL_DATA_DIR,   FILENAME, MODE)
#define File_Open_Personal(FILENAME,MODE)   File_Open_Ex(SEARCHDIR_PERSONAL_DATA_DIR, FILENAME, MODE)
#define File_ReadBlockFile(FILENAME,BUFFER,LENGTH)          File_ReadBlockFile_Ex(SEARCHDIR_GLOBAL_DATA_DIR,   FILENAME, BUFFER, LENGTH)
#define File_ReadBlockFile_Personal(FILENAME,BUFFER,LENGTH) File_ReadBlockFile_Ex(SEARCHDIR_PERSONAL_DATA_DIR, FILENAME, BUFFER, LENGTH)
#define File_ReadWholeFile(FILENAME)        File_ReadWholeFile_Ex(SEARCHDIR_GLOBAL_DATA_DIR, FILENAME)
#define ChunkFile_Open(FILENAME)            ChunkFile_Open_Ex(SEARCHDIR_GLOBAL_DATA_DIR,   FILENAME)
#define ChunkFile_Open_Personal(FILENAME)   ChunkFile_Open_Ex(SEARCHDIR_PERSONAL_DATA_DIR, FILENAME)

extern bool File_Exists_Ex(enum SearchDirectory dir, const char *filename);
extern uint8 File_Open_Ex(enum SearchDirectory dir, const char *filename, uint8 mode);
extern uint32 File_ReadBlockFile_Ex(enum SearchDirectory dir, const char *filename, void *buffer, uint32 length);
extern void *File_ReadWholeFile_Ex(enum SearchDirectory dir, const char *filename);
extern uint32 File_ReadFile_Ex(enum SearchDirectory dir, const char *filename, void *buf);
extern uint8 ChunkFile_Open_Ex(enum SearchDirectory dir, const char *filename);

#endif /* FILE_H */
