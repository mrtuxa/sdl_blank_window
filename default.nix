with import <nixpkgs> {};

stdenv.mkDerivation {
  name = "my-app";
  src = ./.;

  buildInputs = [ SDL2 ];

  buildPhase = "make build";

  installPhase = ''
    mkdir -p $out/bin
    cp main $out/bin/
  '';
}
