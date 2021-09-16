---
layout: page
title: Posts
permalink: /posts/
---

<ul>
  {% for post in site.posts %}
    <li>
      <a href="{{ post.url | relative_url }}">{{post.title}}</a> <br>
      {{ post.content | strip_html | truncatewords:30 }}
      <a href="{{ post.url | relative_url }}">See More</a>
    </li>
     <br>
  {% endfor %}
</ul>