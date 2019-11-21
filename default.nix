{ pkgs ? import ./pkgs.nix {} }:

with pkgs;

{
  correct-horse = stdenv.mkDerivation rec {
    name = "correct-horse";
    src = stdenv.lib.cleanSource ./.;

    nativeBuildInputs = [ autoreconfHook pkgconfig ];
    buildInputs = [ gtk3 ];

    enableParallelBuilding = true;
  };
}
