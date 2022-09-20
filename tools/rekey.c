#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlcipher/sqlite3.h>

int main(int argc, char **argv) {
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;

  if (argc < 4) {
    printf("Usage: %s <dbfile> <old-key> <new-key>\n", argv[0]);
    exit(1);
  }
  rc = sqlite3_open(argv[1], &db);
  if( rc ){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return(1);
  }
  rc = sqlite3_key(db, argv[2], strlen(argv[2]));
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
    goto end;
  }
  rc = sqlite3_rekey(db, argv[3], strlen(argv[3]));
  if( rc!=SQLITE_OK ){
    fprintf(stderr, "SQL rekey error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  }
end:
  sqlite3_close(db);

  return 0;
}

