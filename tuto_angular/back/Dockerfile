FROM node:16

RUN mkdir -p /app
WORKDIR /app

RUN npm install -g @nestjs/cli

COPY . /app

RUN mv ./entrypoint.sh /usr/local/bin/ && chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 3000

ENTRYPOINT ["entrypoint.sh"]

CMD ["npm", "run", "start:dev"]