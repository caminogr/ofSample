import axios from "axios";

const instance = axios.create({
  baseURL: 'http://localhost:3000',
  timeout: 1000,
});

export const postPosition = async position => {
  try {
    await instance.post('/api/notify-position', { position });
  } catch (e) {
    console.error('error: ', e)
    return null;
  }
};

export const postText = async text => {
  try {
    await instance.post('/api/post-text', { text })
  } catch (e) {
    console.error('error: ', e)
    return null;
  }
};
