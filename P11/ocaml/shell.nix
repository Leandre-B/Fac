{ pkgs ? import <nixpkgs> {} }:
  pkgs.mkShell {
    packages = with pkgs; [

        ocaml
        ocamlPackages.ocaml-lsp

    ];
}