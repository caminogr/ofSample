import axios from "axios";

const instance = axios.create({
  baseURL: 'http://localhost:3000',
  timeout: 1000,
});

export const postPosition = async (x, y) => {
  console.log('send x,y: ', x, y)
  try {
    await instance.post(`/api/notify-position`, {
      x, y,
    });
  } catch (e) {
    console.error('error: ', e)
    return null;
  }
};
