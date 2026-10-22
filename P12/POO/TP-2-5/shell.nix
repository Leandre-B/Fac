{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  nativeBuildInputs = with pkgs; [
    cmake
    pkg-config
    clang-tools
  ];

  buildInputs = with pkgs; [
    sfml_2
    # libGL
    # libx11
    # libxrandr
    # libxcursor  
    # libxi
    # xorgproto
  ];
}