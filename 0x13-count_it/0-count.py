#!/usr/bin/python3
"""recursive function that queries the Reddit API and returns
a count of all hot articles for a given subreddit"""
import requests


def count_words(subreddit, word_list):
    """recursive function that queries the Reddit API and returns
    a count of all hot articles for a given subreddit"""
    url = "https://www.reddit.com/r/{}/hot.json?after=t3_".format(subreddit)
    headers = {'User-Agent': 'My User Agent 1.0'}
    response = requests.get(url, headers=headers, allow_redirects=False)
    if response.status_code != 200:
        return 0
    data = response.json()
    posts = data.get('data').get('children')
    if not posts:
        return 0
    for post in posts:
        title = post.get('data').get('title')
        for word in word_list:
            if word in title:
                count += 1
    if data.get('data').get('after'):
        return count + count_words(subreddit, word_list)
    return count
