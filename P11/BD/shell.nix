{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  packages = [
    pkgs.postgresql
  ];

  shellHook = ''
    export PGDATA="$PWD/.postgres"
    export PGHOST="$PGDATA"
    export PGPORT=5432
    export PGDATABASE=postgres

    start-postgres() {
      if [ ! -d "$PGDATA/base" ]; then
        echo "sInitialisation de PostgreSQL..."

        initdb \
          --pgdata="$PGDATA" \
          --auth=trust \
          --no-locale \
          --encoding=UTF8
      fi

      if pg_ctl -D "$PGDATA" status >/dev/null 2>&1; then
        echo "PostgreSQL est déjà démarré."
        return
      fi

      echo "Démarrage de PostgreSQL..."

      pg_ctl \
        -D "$PGDATA" \
        -l "$PGDATA/postgresql.log" \
        -o "-k $PGDATA" \
        start

      echo "PostgreSQL démarré."
    }

    stop-postgres() {
      if pg_ctl -D "$PGDATA" status >/dev/null 2>&1; then
        pg_ctl -D "$PGDATA" stop
        echo "PostgreSQL arrêté."
      else
        echo "PostgreSQL n'est pas démarré."
      fi
    }
  '';
}