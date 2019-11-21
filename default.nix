{ pkgs ? import ./pkgs.nix {} }:

with pkgs;

{
  correct-horse = stdenv.mkDerivation rec {
    name = "correct-horse";
    src = lib.cleanSource ./.;

    nativeBuildInputs = [ meson ninja pkgconfig ];
    buildInputs = [ gtk3 ];
  };
}
