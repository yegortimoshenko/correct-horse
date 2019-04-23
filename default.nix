{ pkgs ? import ./pkgs.nix {} }: with pkgs;

stdenv.mkDerivation rec {
  name = "correct-horse";
  src = stdenv.lib.cleanSource ./.;

  nativeBuildInputs = [ autoreconfHook pkgconfig ];
  buildInputs = [ gtk3 ];

  enableParallelBuilding = true;
}
