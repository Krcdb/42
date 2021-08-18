FROM node:16

RUN mkdir -p /app
WORKDIR /app

RUN npm install -g npm@latest
RUN npm install -g @angular/cli@latest

COPY . /app

RUN mv ./entrypoint.sh /usr/local/bin/ && chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 4200

ENTRYPOINT ["entrypoint.sh"]

CMD ["ng", "serve", "--host=0.0.0.0"]