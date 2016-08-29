#!/bin/sh
EXCLUDE="*.json .git* *.tar.gz"
VERSION=$1
OUTPUT=Multiplo-Duinobot-${VERSION}.tar.gz


sha(){
    echo SHA-256:$(sha256sum $1  | cut -d' ' -f1)
}


EXCLUDE_ARGS=''
for pattern in $EXCLUDE; do
    EXCLUDE_ARGS="$EXCLUDE_ARGS --exclude=$pattern"
done

tar cvzf $OUTPUT $EXCLUDE_ARGS .
SHA=$(sha $OUTPUT)
SIZE=$(wc --bytes $OUTPUT | cut -d' ' -f1)


BOILERPLATE=$(cat <<EOF
        {
          "name": "Duinobot AVR Boards",
          "architecture": "avr",
          "version": "$VERSION",
          "category": "Contributed",
          "help": {
            "online": ""
          },
          "url": "https://github.com/Robots-Linti/Multiplo/raw/binary/$OUTPUT",
          "archiveFileName": "$OUTPUT",
          "checksum": "$SHA",
          "size": "$SIZE",
          "boards": [
            {
              "name": "Duinobot v1.x"
            },
            {
              "name": "Duinobot v2.x"
            }
          ],
          "toolsDependencies": [
            {
              "packager": "arduino",
              "name": "avr-gcc",
              "version": "4.8.1-arduino5"
            },
            {
              "packager": "arduino",
              "name": "avrdude",
              "version": "6.0.1-arduino5"
            }
          ]
        }
EOF
)

echo "---------------------------------------------------------"
echo "$BOILERPLATE"
echo "---------------------------------------------------------"
