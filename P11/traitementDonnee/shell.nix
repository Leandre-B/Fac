{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    (pkgs.python3.withPackages (ps: [
      ps.pandas
    ]))
  ];
  packages = [
    pkgs.R
  ];

}