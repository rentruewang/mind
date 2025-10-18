# Platforms Vs Applications

## Characteristics

Platforms needs to be reliable / repeatable, applications just needs to focus on one aspect.

Platforms needs to be more generic than applications.

Platforms have changeable content, which does not require effort on their end.

If customer access content (no update effort) only over the application, then it’s a platform.

## Example

Games are applications.

Social media, search engines, smart phones are platforms.

Databases are platforms.

ORM are platforms.

## B2B vs B2C

B2B companies are more applications, and B2C companies are more platforms.

B2C is less developer focused.

B2C is most likely platforms, B2B not necessarily so.


## Innovation

Innovation = high value
Software happens to be good for business because it's so reproducible.

# OSS vs closed

B2b platform needs opensource

B2c does not.

Because of customer caring or not

OSS makes money by being a valuable derivative market.

## OSS Monetization

In the generalized sense,

Applications:
    - Do 1 thing (used 1 way).
    - 1 pass of info exchange maximum (request + response count as 1).

Platforms / libraries:
    - Do many things (in ecosystem).
    - 2 way info exchange, interactive.

If we go by that definition, OSS application provides little space for monetization,
and this is why a lot of OSS apps would become closed source / source avaialable due to competition, example: Grafana, HashiCorp, CockroachDB. Elastic, Sentry.

Platforms provide rooms to build additional services on top due to **many ways** you can use a platform (you open souce a way, close source a way for monetization). E.g. DataBricks can build on top of spark with hosting, monitoring, custom runtime etc. Now DBT is an interesting case. It is much like a SQL DB, so it leans closer to application, but since it's doing ingestion it can visualize a lot of interesting endpoints etc, and the value added is much bigger than an UI for DB (cause DB would not fail so long as syntax foHashicorpr SQL is correct). Building UI for DBT requires interactivity for DBT core, making it platform like I would say (different from *DB).
