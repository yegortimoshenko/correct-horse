with import <nixpkgs> {};

stdenv.mkDerivation rec {
  name = "correct-horse";
  src = stdenv.lib.cleanSource ./.;

  nativeBuildInputs = [ autoreconfHook pkgconfig ];
  buildInputs = [ gtk3 ];

  enableParallelBuilding = true;
}
